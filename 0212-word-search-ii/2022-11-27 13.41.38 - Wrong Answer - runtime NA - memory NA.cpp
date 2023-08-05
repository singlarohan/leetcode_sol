class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        unordered_set<string> mp;
        string temp;
        auto solve = [&](int i, int j, auto &&self){
            if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*'){
                if(mp.find(temp) != mp.end()){
                    ans.push_back(temp);
                    mp.erase(temp);
                }
                return;
            }
            temp += board[i][j];
            board[i][j] = '*';
            self(i + 1, j, self);
            self(i, j + 1, self);
            self(i - 1, j, self);
            self(i, j - 1, self);
            board[i][j] = temp.back();
            temp.pop_back();
            return;
        };
        for(int i = 0; i < words.size(); i++)
            mp.insert(words[i]);
        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words[0].size(); j++)
                solve(i, j, solve);
        return ans;
    }
};