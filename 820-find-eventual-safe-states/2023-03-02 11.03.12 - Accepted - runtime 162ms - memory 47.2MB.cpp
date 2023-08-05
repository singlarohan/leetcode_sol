class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        unordered_set<int> ifcycle;
        auto dfs = [&](int i, auto &&self) -> bool{
            vis[i] = 2;
            for(auto x:graph[i]){
                if(vis[x] == 2 || (!vis[x] && self(x, self)))
                    return true;
            }
            vis[i] = 1;
            return false;
        };
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!vis[i] && dfs(i, dfs));
            if(vis[i] != 2) ans.push_back(i);
        }
        return ans;
    }
};