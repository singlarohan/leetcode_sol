class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        unordered_map<string, int> mp;
        unordered_map<string, bool> vis;
        for(auto s:strs) 
            mp[s]++;
        //swap every character and check if it exists
        int count{};
        queue<string> q;
        q.push(strs[0]);
        // mp[strs[0]] = 1;
        // fix duplicates stuff
        while(!q.empty()){
            string s = q.front();
            q.pop();
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    swap(s[i], s[j]);
                    if(mp.find(s) != mp.end()) {
                        count++;
                        if(s[i] != s[j])
                        q.push(s);
                    }
                    swap(s[i], s[j]);
                }
            }
            st.erase(s);
        }
        return count;
    }
};