class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wList) {
        int n = wList.size();
        int m = beginWord.size();
        unordered_set<string> st;
        for(int i = 0; i < n; i++)
            st.insert(wList[i]);
        st.erase(beginWord);
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        int sos{INT_MAX};
        while(!q.empty()){
            int count = q.size();
            vector<string> to_rem;
            while(count--){
                vector<string> t = q.front();
                string word = t.back();
                q.pop();
                if(word == endWord){
                    if(sos < word.size()){
                        return ans;
                    }
                    ans.push_back(t);
                    sos = word.size();
                    continue;
                }
                else{
                    for(int i = 0; i < m; i++){
                        char temp = word[i];
                        for(char j = 'a'; j <= 'z'; j++){
                            word[i] = j;
                            if(st.find(word) != st.end()){
                                t.push_back(word);
                                to_rem.push_back(word);
                                q.push(t);
                                t.pop_back();
                            }
                        }
                        word[i] = temp;
                    }
                }
            }
            for(auto s:to_rem)
            st.erase(s);
        }
        return ans;
    }
};