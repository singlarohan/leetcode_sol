class Solution {
public:
    int partitionString(string s) {
        vector<bool> mp(26, false);
        int ans{1};
        for(int i = 0; i <s.size(); i++){
            if(mp[s[i] - 'a']){
                ans++;
                mp = vector<bool> (26, false);
            }
            mp[s[i] - 'a'] = true;
        }
        return ans;
    }
};