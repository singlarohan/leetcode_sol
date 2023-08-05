class Solution {
public:
    void solve(int dir, vector<vector<int>> &matrix, int i, int j, int n, int v){
        if(i>=n || j >= n || matrix[i][j])
            return;
        if(dir == 0){
            while(j < n && !matrix[i][j]){
                matrix[i][j] = ++v;
                j++;
            }
            i++, j--;
        }
        if(dir == 1){
            while(i < matrix.size() && !matrix[i][j]){
                matrix[i][j] = ++v;
                i++;
            }
            i--, j--;
            // solve((dir+1)%4, ans, matrix, i, j - 1, dp);
        }
        if(dir == 2){
            while(j >= 0 && !matrix[i][j]){
                matrix[i][j] = ++v;
                j--;
            }
            j++, i--;
            // solve((dir+1)%4, ans, matrix, i - 1, j, dp);
        }
        if(dir == 3){
            while(i >= 0 && !matrix[i][j]){
                matrix[i][j] = ++v;
                i--;
            }
            i++, j++;
            // solve((dir+1)%4, ans, matrix, i, j + 1, dp);
        }
        solve((dir+1)%4, matrix, i, j, n, v);
    }
    
    vector<vector<int>> generateMatrix(int n) {
        // 0 -> l to r, 1 -> up to down, 2 -> r to l, 3 -> down to up
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        solve(0, matrix, 0, 0, n, 0);
        return matrix;
    }
};