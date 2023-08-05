class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int, int> mp;
        mp[t.back()]++;
        for(int i = 0; i < s.size(); i++){
            mp[t[i]]++;
            mp[s[i]]--;
            if(mp[s[i]] == 0)
                mp.erase(s[i]);
            if(mp[t[i]] == 0)
                mp.erase(t[i]);
        }
        for(auto it:mp)
            return it.first;
        return 'c';
    }
};