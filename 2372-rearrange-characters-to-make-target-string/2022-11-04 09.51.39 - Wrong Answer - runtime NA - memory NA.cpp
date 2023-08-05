class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> smp(26, 0);
        vector<int> tmp(26, 0);
        for(int i = 0; i < target.size(); i++)
            tmp[target[i] - 'a']++;
        for(int i = 0; i < s.size(); i++)
            if(tmp[s[i] - 'a'] != 0)
                smp[s[i] - 'a']++;
        int mini{INT_MAX};
        for(int i = 0; i < 26; i++)
            if(smp[i] != 0)
                mini = min(smp[i]/tmp[i], mini);
        return mini;
    }
};