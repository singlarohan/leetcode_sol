class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans{};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dp[i][j])
                    continue;                    
                dp[i][j] = true;
                if(board[i][j] == 'X'){
                    if(j + 1 < board[0].size() && board[i][j + 1] == 'X'){
                        j++;
                        while(j < board[0].size() && board[i][j] == 'X'){
                            dp[i][j] = true;
                            j++;
                        }
                    }
                    else{
                        int k = i + 1;
                        while(k < board.size() && board[k][j] == 'X'){
                            dp[k][j] = true;
                            k++;
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};