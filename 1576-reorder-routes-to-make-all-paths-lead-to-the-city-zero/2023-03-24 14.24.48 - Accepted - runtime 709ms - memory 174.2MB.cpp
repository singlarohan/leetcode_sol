class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // vector<bool> vis(n, 0);
        vector<vector<vector<int>>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back({it[1], 0});
            adj[it[1]].push_back({it[0], 1});
        }
        int ans{};
        auto dfs = [&](int i, int prnt, auto &&self) -> void{
            // vis[i] = true;
            // int ans{};
            for(auto it:adj[i]){
                // if(!vis[it[0]]){
                if(prnt != it[0]){
                    // cout<<it[0]<<" "<<it[1]<<endl;
                    if(!it[1]) ans++;
                    // vis[it[0]] = 1;
                    self(it[0], i, self);
                }
            }
        };
        dfs(0, -1, dfs);
        return ans;
    }
};