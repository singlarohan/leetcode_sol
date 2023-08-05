class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        string temp;
        for(int i = 0; i <= s.size() - 10; i++){
            temp = s.substr(i, 10);
            mp[temp]++;
        }
        vector<string> ans;
        for(auto it:mp) 
            if(it.second >= 2) ans.push_back(it.first);
        return ans;
    }
};