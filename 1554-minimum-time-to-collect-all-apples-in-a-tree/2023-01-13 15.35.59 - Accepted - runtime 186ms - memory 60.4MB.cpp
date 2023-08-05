class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(hasApple.size());
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // int c{};
        // for(int i = 0; i < hasApple.size(); i++) if(hasApple[i]) c++;
        int ans{};
        vector<bool> vis(hasApple.size(), false);
        auto solve = [&](int i, auto &&self) -> bool{
            if(adj[i].empty()) return hasApple[i];
            vis[i] = true;
            bool temp = hasApple[i];
            for(int j = 0; j < adj[i].size(); j++){
                if(!vis[adj[i][j]]){
                    bool tempo = self(adj[i][j], self);
                    if(tempo) ans += 2;
                    temp |= tempo;
                }
            }
            return temp;
        };
        solve(0, solve);
        return ans;
    }
};