class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int cnt = 0;
        int max_x = INT_MIN, min_x = INT_MAX;
        int max_y = INT_MIN, min_y = INT_MAX;

        for(auto it:circles){
            max_x = max(max_x, it[0] + it[2]);
            min_x = min(min_x, it[0] - it[2]);
            max_y = max(max_y, it[1] + it[2]);
            min_y = min(min_y, it[1] - it[2]);
        }
        for(int i = min_x; i <= max_x ; i++){
            for(int j = min_y ; j <= max_y; j++){
                for(auto &it : circles){
                    int x = it[0], y = it[1];
                    int r = it[2];

                    int d = (x - i) * (x - i) + (y - j) * (y - j);

                    if(d <= r * r){
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};