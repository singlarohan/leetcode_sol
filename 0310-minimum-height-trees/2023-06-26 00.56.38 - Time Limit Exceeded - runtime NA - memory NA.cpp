class Solution {
private:
    vector<int> height;
public:
    int dfs(int node, int parent, vector<vector<int>> & adj){
        // if(height[node] != -1) return height[node];
        int ans {};
        for(auto x:adj[node]){
            if(x != parent)
            ans = max(ans, dfs(x, node, adj));
        }
        return 1 + ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        height = vector<int> (n, -1);
        for(int i = 0; i < n; i++){
            if(height[i] == -1)
                height[i] = dfs(i, -1, adj);
        }
        for(auto x:height) cout<<x<<" ";
        map<int, vector<int>> mp;
        for(int i = 0; i < height.size(); i++){
            mp[height[i]].push_back(i);
        }
        return (mp.begin()) -> second;

    }
};