class Solution {
public:
    bool dfs(string &s, int i, int j, int c, vector<vector<char>> &board){
        if(c >= s.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != s[c] || board[i][j] == '*') 
            return false;
        char temp = board[i][j];
        
        board[i][j] = '*';
        
        bool flag{};
        if(dfs(s, i + 1, j, c + 1, board) || dfs(s, i, j + 1, c + 1, board)
        || dfs(s, i - 1, j, c + 1, board) || dfs(s, i, j - 1, c + 1, board)) flag = true;
        
        board[i][j] = temp;
        
        return flag;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(auto &x:words){
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[0].size(); j++)
                    if(board[i][j] == x[0] && dfs(x, i, j, 0, board)){ 
                        ans.push_back(x);
                        i = board.size();
                        break;
                    }
            }
        }
        return ans;
    }
};