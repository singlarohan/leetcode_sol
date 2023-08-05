class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> mp(26, 0);
        mp[t.back() - 'a']++;
        for(int i = 0; i < s.size(); i++){
            mp[t[i] - 'a']++;
            mp[s[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
            if(mp[i])
                return 'a' + i;
        return 'c';
        // auto it = mp.begin();
        // return it -> first;
    }
};