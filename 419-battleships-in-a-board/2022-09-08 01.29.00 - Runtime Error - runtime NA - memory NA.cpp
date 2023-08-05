class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans{};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'X'){
                    if(j + 1 < board[0].size() && board[i][j + 1] == 'X'){
                        j++;
                        while(j < board[0].size() && board[i][j] == 'X'){
                            board[i][j] = '.';
                            j++;
                        }
                    }
                    else{
                        int k = i + 1;
                        while(k < board.size() && board[k][j] == 'X'){
                            board[k][j] = '.';
                            k++;
                        }
                    }
                    ans++;
                }
                board[i][j] = '.';
            }
        }
        return ans;
    }
};