class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> mp;
        mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = true;
        mp['A'] = mp['E'] = mp['I'] = mp['O'] = mp['U'] = true;
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(l < r && !mp[s[l]])
                l++;
            while(r > l && !mp[s[r]])
                r--;
            if(l >= r)
                return s;
            swap(s[l], s[r]);
            l++, r--;
        }
        return s;
    }
};