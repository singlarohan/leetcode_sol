class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, 0);
        int ans{}, begin{};
        for(int i = 0; i< s.size(); i++){
            if(mp[s[i]] != 0){
                while(mp[s[i]] != 0){
                    mp[s[begin]] = 0;
                    begin++;
                }
            }
            mp[s[i]]++;
            ans = max(ans, 1 + i - begin);
        }
        return ans;
    }
};