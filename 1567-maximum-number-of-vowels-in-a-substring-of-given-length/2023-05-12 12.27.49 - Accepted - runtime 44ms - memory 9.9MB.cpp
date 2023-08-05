class Solution {
public:
    int maxVowels(string s, int k) {
        //simple sliding window
        unordered_map<char, bool> isv;
        isv['a'] = isv['e'] = isv['i'] = isv['o'] = isv['u'] = true;
        int ans{}, vow{};
        int i{};
        while(i < k){
            if(isv.find(s[i]) != isv.end()) vow++;
            i++;
        }
        ans = vow;
        for(; i < s.size(); i++){
            if(isv.find(s[i - k]) != isv.end()) vow--;
            if(isv.find(s[i]) != isv.end()) vow++;
            ans = max(ans, vow);
        }
        return ans;
    }
};