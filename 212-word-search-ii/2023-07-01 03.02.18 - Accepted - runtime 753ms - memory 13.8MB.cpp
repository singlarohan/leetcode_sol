class Solution {
private:
    vector<string> ans;
    unordered_set<string> mp;
    string temp;
    unordered_map<string, int> prefset;
public:
    void solve(int i, int j, vector<vector<char>> &board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
                 || board[i][j] == '*') return;
        
        temp += board[i][j];

        if(prefset.find(temp) == prefset.end()) {
            temp.pop_back();
            return;
        }

        if(mp.find(temp) != mp.end()){
            ans.push_back(temp);
            mp.erase(mp.find(temp));
            
            prefset[temp]--;
            //agar 0 prefix reh jayega iss size ka
            //toh fir isey set mein se erase krdenge
            if(prefset[temp] == 0) prefset.erase(temp);
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
        //this hashset just stores all the words given :D
        for(int i = 0; i < words.size(); i++){
            mp.insert(words[i]);
            //this set contains set of all possible prefixes
            //for all the given words in prefset
            for(int j = 0; j < words[i].size(); j++)
                prefset[words[i].substr(0, j + 1)]++;
        }

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                solve(i, j, board);
        return ans;
    }
};