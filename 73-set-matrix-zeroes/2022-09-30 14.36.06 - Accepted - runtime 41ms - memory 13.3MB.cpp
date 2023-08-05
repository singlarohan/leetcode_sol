class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //O(m+n) space
        unordered_map<int, bool> row;
        unordered_map<int, bool> col;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(row.find(i) != row.end() || col.find(j) != col.end())
                matrix[i][j] = 0;
            }
        }
    }
};