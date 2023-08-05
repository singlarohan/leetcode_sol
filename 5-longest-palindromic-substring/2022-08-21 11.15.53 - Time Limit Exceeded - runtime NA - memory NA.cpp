class Solution {
public:
    
    bool ifPalin(string s, int begin, int end, vector<vector<int>> &dp){
        if(dp[begin][end] != -1)
            return dp[begin][end];
        while(begin < end){
            if(s[begin] != s[end])
                return dp[begin][end] = 0;
            begin++;
            end--;
        }
        return dp[begin][end] = 1;
    }
    void solve(string s, int i, int j, string &ans, vector<vector<int>> &dp){
        if(i > j)
            return;
        if(ifPalin(s, i, j, dp)){
            if(j - i + 1> ans.size()){
                ans = "";
                while(i <= j){
                    ans.push_back(s[i]); 
                    i++;
                }
            }
            return;
        }
        solve(s, i+1, j, ans, dp);
        solve(s, i, j-1, ans, dp);
    }
    string longestPalindrome(string s) {
        vector<vector<int>> dp(1000, vector<int> (1000, -1));
        string ans;
        solve(s, 0, s.size() - 1, ans, dp);
        return ans;
    }
};