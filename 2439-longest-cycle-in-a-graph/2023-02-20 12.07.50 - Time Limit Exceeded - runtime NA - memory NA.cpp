class Solution {
public:
    int longestCycle(vector<int>& edges) {
        vector<bool> vis(edges.size(), false);
        int ans{-1};
        auto solve = [&](int x, int count, int to_find, auto &&self){
            if(vis[x]){
                if(x == to_find) ans = max(ans,count);
                return;
            }
            vis[x] = true;
            if(edges[x] != -1)
            self(edges[x], count + 1, to_find, self);
            vis[x] = false;
            return;
        };
        for(int i = 0; i < edges.size(); i++) 
            solve(i, 0, i, solve);

        return ans;
    }
};