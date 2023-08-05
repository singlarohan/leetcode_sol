class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> st;
        cout<<circles.size()<<endl;
        //boundary of grid
        //(x - r, y + r), (x + r, y + r) 
        //(x - r, y - r), (x + r, y - r);
        for(auto it:circles){
            for(int x = it[0] - it[2]; x <= it[0] + it[2]; x++){
                for(int y = it[1] - it[2]; y <= it[1] + it[2]; y++){
                    if(pow(it[0] - x, 2) + pow(it[1] - y, 2) <= pow(it[2], 2))
                        st.insert({x, y});
                }
            }
        }
        return st.size();
    }
};