class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;

        // if(s.size() <= 10) return ans;

        unordered_map<string, int> mp;
        string temp;
        for(int i = 0; i <= (int)s.size() - 10; i++){
            temp = s.substr(i, 10);
            mp[temp]++;
        }

        for(auto it:mp) 
            if(it.second >= 2) ans.push_back(it.first);

        return ans;
    }
};