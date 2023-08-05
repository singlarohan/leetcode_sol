class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n + 1);
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<bool> vis(n + 1, 0);
        auto dfs = [&](int i, auto &&self) -> int{
            int ans{INT_MAX};
            for(auto it:adj[i]){
                ans = min(ans, it[1]);
                if(!vis[it[0]]){
                    vis[it[0]] = 1;
                    // cout<<i<<" "<<it[0]<<" "<<ans<<endl;
                    ans = min(ans, self(it[0], self));
                    // vis[it[0]] = 0;
                }
            }
            return ans;
        };
        vis[1] = true;
        return dfs(1, dfs);
    }
};