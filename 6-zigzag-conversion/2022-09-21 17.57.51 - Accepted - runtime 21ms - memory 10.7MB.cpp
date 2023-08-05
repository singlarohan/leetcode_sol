class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> temp(numRows, "");
        for(int i = 0; i < s.size();){
            int k = 0;
            while(i < s.size() && k < numRows){
                temp[k] += s[i];
                k++, i++;
            }
            k = numRows - 2;
            while(i < s.size() && k > 0){
                temp[k] += s[i];
                k--, i++;
            }
        }
        string ans;
        for(auto x:temp)
            ans += x;
        return ans;
    }
};