class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l{};
        int ans{};
        vector<int> hash(26, -1);
        for(int i = 0; i < s.size(); i++){
            ans = max(ans, i - l);
            if(hash[s[i] - 'a'] != -1){
                ans = max(i - l, ans);
                while(l < i && l != hash[s[i] - 'a'] + 1){
                    hash[s[l] - 'a'] = -1;
                    l++;
                }
            }
            hash[s[i] - 'a'] = i;
        }
        return ans;
    }
};