class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> dp_col(board.size(), vector<bool> (10,false));        
        vector<vector<bool>> dp_row(board[0].size(), vector<bool> (10,false));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.')
                    continue;
                if(dp_col[i][board[i][j] - '0'] || dp_row[j][board[i][j] - '0'])
                    return false;
                dp_col[i][board[i][j] - '0'] = true;
                dp_row[j][board[i][j] - '0'] = true;
            }
        }
        return true;
    }
};