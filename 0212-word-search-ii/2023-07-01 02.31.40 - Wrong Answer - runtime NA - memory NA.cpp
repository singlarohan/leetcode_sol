class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        unordered_set<string> mp;
        unordered_map<int, unordered_set<string>> premp;
        string temp;
        int max_len{};
        auto solve = [&](int i, int j, auto &&self){
            if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*' || temp.size() > max_len) return;
            temp += board[i][j];
            if(mp.find(temp) != mp.end()){
                ans.push_back(temp);
                mp.erase(mp.find(temp));
                premp[temp.size()].erase(temp);
            }
            if(premp[temp.size()].find(temp) == premp[temp.size()].end()){
                temp.pop_back();
                return;
            }
            board[i][j] = '*';
            self(i + 1, j, self);
            self(i, j + 1, self);
            self(i - 1, j, self);
            self(i, j - 1, self);
            board[i][j] = temp.back();
            temp.pop_back();
            return;
        };
        for(int i = 0; i < words.size(); i++){
            mp.insert(words[i]);
            max_len = max(max_len, (int)words[i].size());
            premp[1].insert(words[i].substr(0, 1));
        }

        for(int i = 2; i <= max_len; i++){
            for(int j = 0; j < words.size(); j++){
                if(words[j].size() < i) continue;
                premp[i].insert(words[j].substr(0, i));
            }
        }

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                solve(i, j, solve);
        return ans;
    }
};