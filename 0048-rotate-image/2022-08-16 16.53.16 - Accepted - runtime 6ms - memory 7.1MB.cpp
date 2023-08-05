class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int j = 0; j < n/2; j++){
            for(int i = j; i<n - 1 - j; i++){
                // swap(matrix[0][i], matrix[n-i-1][0]);
                // swap(matrix[n-i-1][0], matrix[n-1][n-i-1]);
                // swap(matrix[n-1][n-i-1], matrix[i][n-1]);
                swap(matrix[j][i], matrix[n-i-1][j]);
                swap(matrix[n-i-1][j], matrix[n-j-1][n-i-1]);
                swap(matrix[n-j-1][n-i-1], matrix[i][n-j-1]);
            }
        }
    }
};