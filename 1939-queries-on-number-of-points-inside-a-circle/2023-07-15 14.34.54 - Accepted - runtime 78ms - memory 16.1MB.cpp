class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& que) {
        int n = que.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            int x = que[i][0], y = que[i][1];
            int r = que[i][2];
            for(auto &it:points)
                if(pow(x - it[0], 2) + pow(y - it[1], 2) <= pow(r, 2))
                    ans[i]++;
        }
        return ans;
    }
};