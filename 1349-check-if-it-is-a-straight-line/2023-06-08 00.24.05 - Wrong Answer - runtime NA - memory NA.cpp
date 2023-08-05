class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coo) {
        if(coo.size() == 2) return true;
        for(int i = 1; i < coo.size() - 1; i++){
            int y0 = coo[i][1] - coo[i-1][1];
            int x0 = coo[i][0] - coo[i-1][0];
            int y1 = coo[i+1][1] - coo[i][1];
            int x1 = coo[i+1][0] - coo[i][0];
            if((1.0*y0)/x0 != (1.0*y1)/x1) return false;
        }
        return true;
    }
};