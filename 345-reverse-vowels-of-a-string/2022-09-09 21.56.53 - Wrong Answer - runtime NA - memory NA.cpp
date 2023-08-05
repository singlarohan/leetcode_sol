class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> mp;
        mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = true;
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(!mp[s[l]])
                l++;
            while(!mp[s[r]])
                r--;
            if(l >= r)
                return s;
            swap(s[l], s[r]);
            l++, r--;
        }
        return s;
    }
};