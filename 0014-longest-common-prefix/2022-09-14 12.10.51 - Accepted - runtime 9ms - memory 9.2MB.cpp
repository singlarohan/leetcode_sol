class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        int count = temp.size();
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < count; j++){
                if(strs[i][j] != temp[j]){
                    count = j;
                    break;
                }
            }
        }
        string ans;
        for(int i = 0; i < count; i++)
            ans += temp[i];
        return ans;
    }
};