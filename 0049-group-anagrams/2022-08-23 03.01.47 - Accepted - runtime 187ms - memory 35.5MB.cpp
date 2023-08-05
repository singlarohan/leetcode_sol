class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char, int>, int> mp;
        map<char, int> mp1;
        for(int i = 0; i< strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++){
                mp1[strs[i][j]]++;
            }
            if(mp[mp1] != 0){
                ans[mp[mp1] - 1].push_back(strs[i]);
                mp1.clear();
                continue;
            }
            ans.push_back({strs[i]});
            mp[mp1] = ans.size();
            mp1.clear();
        }
        return ans;
    }
};