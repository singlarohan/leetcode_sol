class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wList) {
        int n = wList.size();
        int m = beginWord.size();
        unordered_set<string> st;
        for(int i = 0; i < n; i++)
            st.insert(wList[i]);
        st.erase(beginWord);
        if(st.find(endWord) == st.end()) return {};
        queue<pair<string, int>> q;
        unordered_map<string, int> mp;
        q.push({beginWord, 0});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[word] = level;
            if(word == endWord) break;
            for(int i = 0; i < m; i++){
                char temp = word[i];
                for(char j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        q.push({word, level + 1});
                        st.erase(word);
                    }
                }
                word[i] = temp;
            }
        }
        if(mp.find(endWord) == mp.end()) return {};
        //now we go back from endword to beginword using dfs to find all the possible vectors
        vector<vector<string>> ans;
        vector<string> temp;
        auto dfs = [&](int level, auto &&self){
            if(level == 0) {
                ans.push_back(temp);
                reverse(ans.back().begin(), ans.back().end());
                return;
            }
            string word = temp.back();
            for(int i = 0; i < m; i++){
                char t = word[i];
                for(char j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    if(mp.find(word) != mp.end() && mp[word] == level - 1){
                        temp.push_back(word);
                        self(level - 1, self);
                        temp.pop_back();
                    }
                }
                word[i] = t;
            }
            return;
        };
        temp.push_back(endWord);
        dfs(mp[endWord], dfs);
        return ans;
    }
};