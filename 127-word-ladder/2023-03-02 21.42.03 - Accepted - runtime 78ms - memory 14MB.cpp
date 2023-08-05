class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wList) {
        int m = endWord.size();
        int n = wList.size();
        unordered_set<string> st(wList.begin(), wList.end());
        st.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        if(st.find(endWord) == st.end()) return 0;
        while(!q.empty()){
            string w = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(w == endWord) return cnt;
            for(int i = 0; i < m; i++){
                char temp = w[i];
                for(int j = 0; j < 26; j++){
                    w[i] = j + 'a';
                    if(st.find(w) != st.end()){
                        q.push({w, 1 + cnt});
                        st.erase(w);
                    }
                }
                w[i] = temp;
            }
        }
        return 0;
    }
};