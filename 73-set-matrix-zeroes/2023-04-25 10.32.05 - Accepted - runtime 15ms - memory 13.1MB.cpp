class Solution {
public:
    // void setRowzero(vector<vector<int>> & mat, int i){
    //     for(int j = 0; j < mat[0].size(); j++){

    //     }
    // }

    void setZeroes(vector<vector<int>>& matrix) {
        //O(m+n) space
        // unordered_map<int, bool> row;
        // unordered_map<int, bool> col;
        // for(int i = 0; i < matrix.size(); i++)
        //     for(int j = 0; j < matrix[0].size(); j++)
        //         if(matrix[i][j] == 0)
        //             row[i] = col[j] = true;
        // for(int i = 0; i < matrix.size(); i++)
        //     for(int j = 0; j < matrix[0].size(); j++)
        //         if(matrix[i][j]!= 0 && (row.find(i) != row.end() || col.find(j) != col.end()))
        //         matrix[i][j] = 0;
        //Constant space
        int m = matrix.size(), n = matrix[0].size();
        bool row{}, col{};
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                col = true;
                break;
            }
        }
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                row = true;
                break;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        }
        if(row)
        for(int j = 0; j < n; j++) matrix[0][j] = 0;
        if(col)
        for(int i = 0; i < m; i++) matrix[i][0] = 0;
        
    }
};