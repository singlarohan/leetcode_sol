class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> mp;
        int ans{1};
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                ans++;
                mp.clear();
            }
            mp.insert(s[i]);
        }
        return ans;
    }
};