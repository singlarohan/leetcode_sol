class Solution {
public:
    vector<vector<bool>> visited;
    
    bool solve(int i, int j, vector<vector<char>>& board, string &word, string &temp){
        if(word == temp)
            return true;
        if(temp.size() >= word.size())
            return false;
    
        bool left, right, up, down;
        left = right = up = down = false;
        
        visited[i][j] = true;
        temp.push_back(board[i][j]);
        if(j > 0 && !visited[i][j-1])
        left = solve(i, j - 1, board, word, temp);
        
        if(j < board[0].size() - 1 && !visited[i][j + 1])
        right = solve(i, j + 1, board, word, temp);
        
        if(i > 0 && !visited[i - 1][j])
        up = solve(i - 1, j, board, word, temp);
        
        if(i < board.size() - 1 && !visited[i + 1][j])
        down = solve(i + 1, j, board, word, temp);
        
        temp.pop_back();
        visited[i][j] = false;
        return left || right || up || down;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        visited = vector<vector<bool>> (board.size(), vector<bool> (board[0].size(), false));
        string temp;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(solve(i, j, board, word, temp))
                return true;
            }
        }
        return false;
    }
};