class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        while(1){
            for(int i = 0; i < strs.size() - 1; i++){
                if(strs[i][ans.size()] != strs[i+1][ans.size()])
                    return ans;
            }
            ans.push_back(strs[0][ans.size()]);
        }
        return ans;
    }
};