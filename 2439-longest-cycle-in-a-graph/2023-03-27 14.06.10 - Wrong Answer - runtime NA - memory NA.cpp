class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<bool> vis(edges.size(), false);
        vector<bool> compvis(edges.size(), false);
        int ans{-1};
        auto solve = [&](int x, int count, int to_find, auto &&self){
            if(compvis[x] || vis[x]){
                if(x == to_find) ans = max(ans,count);
                return;
            }
            compvis[x] = true;
            vis[x] = true;
            if(edges[x] != -1)
            self(edges[x], count + 1, to_find, self);
            vis[x] = false;
            return;
        };
        for(int i = 0; i < edges.size(); i++){
            if(!compvis[i])
            solve(i, 0, i, solve);
        }

        return ans;
    }
};