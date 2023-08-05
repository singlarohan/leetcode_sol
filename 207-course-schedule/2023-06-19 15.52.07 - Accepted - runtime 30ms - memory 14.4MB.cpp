class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prereq) {
        //cycle detection
        //return false if cycle detected
        vector<vector<int>> adj(num);
        for(auto it:prereq)
            adj[it[0]].push_back(it[1]);
        vector<int> vis(num, 0);
        // bool ans
        auto dfs = [&](int i, auto &&self){
            if(vis[i] == 1) return false;
            if(vis[i] == 2) return true;
            vis[i] = 1;
            for(auto node:adj[i]){
                vis[i]++;
                if(self(node, self)) return true;
                vis[i]--;
            }
            return false;
        };
        for(int i = 0; i < num; i++){
            if(dfs(i, dfs)) return false;
        }
        return true;
    }
};