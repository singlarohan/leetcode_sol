class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        if(s.size() != t.size())
            return false;
        for(int i = 0; i<s.size(); i++)
            mp[s[i]]++, mp1[t[i]]++;
        if(mp == mp1)
            return true;
        return false;
    }
};