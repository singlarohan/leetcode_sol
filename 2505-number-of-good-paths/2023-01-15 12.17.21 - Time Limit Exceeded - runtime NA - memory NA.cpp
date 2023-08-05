class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
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
            if(vals[i] == cval && i >= k) ans++;
            if(vals[i] > cval) return;
            vis[i] = true;
            for(int j = 0; j < adj[i].size(); j++)
                if(!vis[adj[i][j]])
                    self(adj[i][j], cval, self);
            vis[i] = false;
            return;
        };
        for(k = 0; k < vals.size(); k++)
            solve(k, vals[k], solve);
        return ans;
    }
};