class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //mark as 2 if to change 0 -> 1
        // mark as 3 if to change 1 -> 0
        int m = board.size(), n = board[0].size();
        vector<int> row = {-1,-1,-1,0,0,1,1,1};
        vector<int> col = {-1,0,1,-1,1,-1,0,1};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int ones{};
                for(int k = 0; k < 8; k++){
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if(!(ni < 0 || nj < 0 || ni >= m || nj >= n))
                        if(board[ni][nj] == 1 || board[ni][nj] == 3)
                            ones++;
                }
                cout<<i <<" "<<j<<" "<<ones<<endl;
                if(board[i][j] == 1 && (ones < 2 || ones > 3))
                    board[i][j] = 3;
                if(ones == 3 && board[i][j] == 0)
                    board[i][j] = 2;
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
        return;
    }
};