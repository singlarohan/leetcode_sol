class Solution {
public:
    vector<int> maxivec(vector<int> &ind, vector<vector<int>> &t){
        int n = t.size(), m = t[0].size();
        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++){
            int maxi = INT_MIN;
            for(auto j:ind){
                maxi = max(maxi, t[j][i]);
            }
            ans[i] = max(maxi, ans[i]);
        }
        // for(auto x:ans) cout<<x<<" ";
        // cout<<endl;
        return ans;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int> (26, 0));
        vector<vector<int>> adj(n);
        for(auto it:edges)
            adj[it[0]].push_back(it[1]);
        
        // unordered_set<char> st;
        // for(auto ch:colors) st.insert(ch);
        vector<int> pathvis(n, false);
        vector<int> vis(n, false);
        int maxi{};
        bool cycle = false;
        auto dfs = [&](int i, auto &&self) -> void{
            vis[i] = true;
            pathvis[i] = true;
            int a{};
            for(auto x:adj[i]){
                if(pathvis[x]) cycle = true;
                if(!vis[x]){
                    self(x, self);
                }
            }
            dp[i] = maxivec(adj[i], dp);
            dp[i][colors[i] - 'a']++;
            maxi = max(dp[i][colors[i] - 'a'], maxi);
            pathvis[i] = false;
            return;
        };
        for(int k = 0; k < n; k++) 
            if(!vis[k]) dfs(k, dfs);
        return cycle ? -1 : maxi;
    }
};