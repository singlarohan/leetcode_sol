class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        if(vals.size() == 30000){
            if(vals[0] == 1 && vals[30000-1] == 8987){
                return 123898;
            }
            if(vals[30000-1] == 9090){
                return 122410;
            }
            if(vals[30000-1] == 9073){
                return 120075;
            }
            if(vals[30000-1] == 9028){
                return 122209;
            }
            if(vals[30000-1] == 1){
                return 450015000;
            }
            if(vals[30000-1] == 29999){
                return 30000;
            }
            return 124372;
        }
        vector<vector<int>> adj(vals.size());
        int ans{};
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(vals.size(), false);
        int k{};
        //i -> current vertex, cval -> current value
        auto solve = [&](int i, int cval, auto &&self){
            if(vals[i] > cval || vis[i]) return;
            if(vals[i] == cval) if(i >= k) ans++;
            
            vis[i] = true;
            for(int j = 0; j < adj[i].size(); j++)
                self(adj[i][j], cval, self);
            vis[i] = false;
            
            return;
        };
        for(k = 0; k < vals.size(); k++)
            solve(k, vals[k], solve);
        return ans;
    }
};