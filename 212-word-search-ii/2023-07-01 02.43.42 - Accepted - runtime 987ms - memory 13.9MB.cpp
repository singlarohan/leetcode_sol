class Solution {
private:
    vector<string> ans;
    unordered_set<string> mp;
    string temp;
    int max_len{};
    vector<unordered_map<string, int>> premp;
public:
    void solve(int i, int j, vector<vector<char>> &board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
                 || board[i][j] == '*' || temp.size() > max_len) return;
        temp += board[i][j];
        if(mp.find(temp) != mp.end()){
            ans.push_back(temp);
            mp.erase(mp.find(temp));
            premp[temp.size()][temp]--;

            if(premp[temp.size()][temp] == 0) premp[temp.size()].erase(temp);
        }
        if(premp[temp.size()].find(temp) == premp[temp.size()].end()){
            temp.pop_back();
            return;
        }
        board[i][j] = '*';
        solve(i + 1, j, board);
        solve(i, j + 1, board);
        solve(i - 1, j, board);
        solve(i, j - 1, board);
        board[i][j] = temp.back();
        temp.pop_back();
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            mp.insert(words[i]);
            max_len = max(max_len, (int)words[i].size());
        }
        
        premp.resize(max_len + 1);

        for(int i = 1; i <= max_len; i++){
            for(int j = 0; j < words.size(); j++){
                if(words[j].size() < i) continue;
                premp[i][words[j].substr(0, i)]++;
            }
        }

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                solve(i, j, board);
        return ans;
    }
};