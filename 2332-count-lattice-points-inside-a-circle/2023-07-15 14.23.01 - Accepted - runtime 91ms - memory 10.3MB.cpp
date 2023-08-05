class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        // set<pair<int, int>> st;
        vector<vector<bool>> st(201, vector<bool> (201, 0));
        //boundary of grid
        //(x - r, y + r), (x + r, y + r) 
        //(x - r, y - r), (x + r, y - r);
        set<vector<int>> vis;
        for(auto &it:circles){
            if(vis.count(it)) continue;
            vis.insert(it);
            for(int x = it[0] - it[2]; x <= it[0] + it[2]; x++){
                for(int y = it[1] - it[2]; y <= it[1] + it[2]; y++){
                    if(pow(it[0] - x, 2) + pow(it[1] - y, 2) <= pow(it[2], 2))
                        st[x][y] = true;
                }
            }
        }
        int ans{};
        for(auto x:st)
            for(auto y:x) ans += y;
        return ans;
    }
};