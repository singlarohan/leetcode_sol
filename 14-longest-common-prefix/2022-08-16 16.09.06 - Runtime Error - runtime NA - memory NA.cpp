class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(!strs[0].empty())
        while(1){
            for(int i = 0; i < strs.size() - 1; i++){
                if(ans.size() > strs[i + 1].size() || ans.size() > strs[i].size() || strs[i][ans.size()] != strs[i+1][ans.size()])
                    return ans;
            }
            ans.push_back(strs[0][ans.size()]);
        }
        return ans;
    }
};