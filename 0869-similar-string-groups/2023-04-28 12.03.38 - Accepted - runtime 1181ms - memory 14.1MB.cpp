class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size();
        unordered_map<string, int> mp;
        // unordered_map<string, bool> vis;
        for(auto s:strs) 
            mp[s]++;
        //swap every character and check if it exists
        int count{};
        queue<string> q;
        // q.push(strs[0]);
        // mp[strs[0]] = 1;
        // fix duplicates stuff
        // fix for the nodes noot reached at the end
        while(!mp.empty()){
            q.push(mp.begin()->first);
            count++;
            while(!q.empty()){
                string s = q.front();
                q.pop();
                // int inc = mp[s];
                // count += (inc) * (inc - 1);
                for(int i = 0; i < n; i++){
                    for(int j = i + 1; j < n; j++){
                        if(s[i] == s[j]) continue;
                        swap(s[i], s[j]);
                        if(mp.find(s) != mp.end()) {
                            // count += inc;
                            q.push(s);
                        }
                        swap(s[i], s[j]);
                    }
                }
                mp.erase(s);
            }
        }
        return count;
    }
};