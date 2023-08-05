class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26, 0);
        for(int i = 0; i < magazine.size(); i++)
            mp[magazine[i] - 'a']++;
        for(int i = 0; i < ransomNote.size(); i++)
            if(mp[ransomNote[i] - 'a'] == 0)
                return false;
            else
                mp[ransomNote[i] - 'a']--;
        return true;
    }
};