class Solution {
public:
    void solve(int dir, vector<int> &ans, vector<vector<int>> &matrix, int i, int j, vector<vector<bool>> &dp){
        if(i>=matrix.size() || j >= matrix[0].size() || dp[i][j])
            return;
        if(dir == 0){
            while(j < matrix[0].size() && !dp[i][j]){
                ans.push_back(matrix[i][j]);
                dp[i][j] = true;
                j++;
            }
            i++, j--;
        }
        if(dir == 1){
            while(i < matrix.size() && !dp[i][j]){
                ans.push_back(matrix[i][j]);
                dp[i][j] = true;
                i++;
            }
            i--, j--;
            // solve((dir+1)%4, ans, matrix, i, j - 1, dp);
        }
        if(dir == 2){
            while(j >= 0 && !dp[i][j]){
                ans.push_back(matrix[i][j]);
                dp[i][j] = true;
                j--;
            }
            j++, i--;
            // solve((dir+1)%4, ans, matrix, i - 1, j, dp);
        }
        if(dir == 3){
            while(i >= 0 && !dp[i][j]){
                ans.push_back(matrix[i][j]);
                dp[i][j] = true;
                i--;
            }
            i++, j++;
            // solve((dir+1)%4, ans, matrix, i, j + 1, dp);
        }
        solve((dir+1)%4, ans, matrix, i, j, dp);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 0 -> l to r, 1 -> up to down, 2 -> r to l, 3 -> down to up
        vector<vector<bool>> dp(matrix.size(), vector<bool> (matrix[0].size(), false));
        vector<int> ans;
        solve(0 ,ans, matrix, 0, 0, dp);
        return ans;
    }
};