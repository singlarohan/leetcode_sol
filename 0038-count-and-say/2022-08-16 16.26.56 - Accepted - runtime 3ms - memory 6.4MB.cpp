class Solution {
public:
    
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string str = countAndSay(n-1);
        int count{1};
        string ans;
        for(int i = 1; i < str.size(); i++){
            if(str[i] != str[i-1]){
                ans.push_back(count + '0');
                ans.push_back(str[i-1]);
                count = 0;
            }
            count++;
        }
        ans.push_back(count + '0');
        ans.push_back(str[str.size() - 1]);
        return ans;
    }
};