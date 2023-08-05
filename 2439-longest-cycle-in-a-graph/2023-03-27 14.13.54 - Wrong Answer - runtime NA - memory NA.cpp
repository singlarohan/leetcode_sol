class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<int> vis(edges.size(), -1);
        vector<bool> compvis(edges.size(), false);
        int ans{-1};
        auto solve = [&](int x, int count, auto &&self){
            if(compvis[x] || vis[x] != -1){
                ans = max(ans, count - vis[x]);
                return;
            }
            compvis[x] = true;
            vis[x] = count;
            if(edges[x] != -1)
            self(edges[x], count + 1, self);
            vis[x] = -1;
            return;
        };
        for(int i = 0; i < edges.size(); i++){
            if(!compvis[i])
            solve(i, 0, solve);
        }

        return ans;
    }
};