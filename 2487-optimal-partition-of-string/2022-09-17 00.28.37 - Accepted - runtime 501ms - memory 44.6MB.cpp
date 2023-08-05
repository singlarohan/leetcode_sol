class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, bool> mp;
        int ans{1};
        for(int i = 0; i <s.size(); i++){
            if(mp[s[i]]){
                ans++;
                mp.clear();
            }
            mp[s[i]] = true;
        }
        return ans;
    }
};