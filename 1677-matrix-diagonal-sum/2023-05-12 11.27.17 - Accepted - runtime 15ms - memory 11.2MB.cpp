class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i = 0;
        int m = mat.size(), n = mat[0].size();
        int ans{};
        while(i < m && i < n){
            ans += mat[i][i];
            if(i != n - i - 1)
            ans += mat[i][n - i - 1];
            i++;
        }
        return ans;
    }
};