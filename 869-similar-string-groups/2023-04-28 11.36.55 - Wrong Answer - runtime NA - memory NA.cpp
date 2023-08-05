class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        unordered_set<string> st;
        for(auto s:strs) st.insert(s);
        //swap every character and check if it exists
        int count{};
        queue<string> q;
        q.push(strs[0]);
        while(!q.empty()){
            string s = q.front();
            q.pop();
            if(st.find(s) != st.end()){
                for(int i = 0; i < n; i++){
                    for(int j = i + 1; j < n; j++){
                        swap(s[i], s[j]);
                        if(st.find(s) != st.end()) count++;
                        q.push(s);
                        swap(s[i], s[j]);
                    }
                }
                st.erase(s);
            }
        }
        return count;
    }
};