class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> mp;
        unordered_map<char, bool> mp1;
        for(auto c:s)
            mp[c]++;
        int i{1};
        for(auto c:s){
            if(mp1[c] = true)
                mp[c]--;
            else{
                mp1[c] = true;
                mp[c]--;
            }
            if(mp[c] == 0)
                mp1.erase(c);
            if(mp1.empty()){
                ans.push_back(i);
                i = 0;
            }
            i++;
        }
        return ans;
    }
};