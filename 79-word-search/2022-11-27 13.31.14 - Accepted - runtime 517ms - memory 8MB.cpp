class Solution {
public:
    // bool solve(int i, int j, vector<vector<char>>& board, string &word, string &temp){
    //     if(!temp.empty() && temp.back() != word[temp.size() - 1])
    //         return false;

    //     if(temp.size() >= word.size())
    //         return false;
    
    //     bool left, right, up, down, curr;
    //     left = right = up = down = false;
        
    //     temp.push_back(board[i][j]);
    //     curr = (word == temp);
        
    //     char tempch = board[i][j];
    //     board[i][j] = '*';
        
    //     if(j > 0 && !board[i][j-1] != '*')
    //     left = solve(i, j - 1, board, word, temp);
        
    //     if(j < board[0].size() - 1 && !board[i][j+1] != '*')
    //     right = solve(i, j + 1, board, word, temp);
        
    //     if(i > 0 && !board[i - 1][j] != '*')
    //     up = solve(i - 1, j, board, word, temp);
        
    //     if(i < board.size() - 1 && !board[i + 1][j] != '*')
    //     down = solve(i + 1, j, board, word, temp);
        
    //     temp.pop_back();
    //     board[i][j] = tempch;
    //     return curr || left || right || up || down;
    // }

    bool exist(vector<vector<char>>& board, string word) {
        auto solve = [&](int i, int j, int count, auto &&self){
            if(count == word.size())
                return true;
            if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*' || board[i][j] != word[count])
                return false;
            char temp = board[i][j];
            board[i][j] = '*';
            bool ans = self(i + 1, j, count + 1, self) ||
                       self(i, j + 1, count + 1, self) ||
                       self(i - 1, j, count + 1, self) ||
                       self(i, j - 1, count + 1, self);
            board[i][j] = temp;
            return ans;
        };
        string temp;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(solve(i, j, 0, solve))
                    return true;
        return false;
    }
};