class Solution {
public:
    int solve(int i, string &s, int op_count, vector<vector<int>> &dp){
        if(i >= s.size()){
            if(op_count == 0)
                return 0;
            return INT_MIN;
        }
        if(dp[i][op_count] != -1)
            return dp[i][op_count];
        if(op_count == 0 && s[i] == ')')
            return 0;
        int ans{};
        if(s[i] == '(')
            ans = 1 + solve(i + 1, s, op_count + 1, dp);
        else
            ans = 1 + solve(i + 1, s, op_count - 1, dp);
        if(op_count == 0) ans = max(0, ans); 
        return dp[i][op_count] = ans;
    }
    
    int longestValidParentheses(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size() + 1, -1));
        int ans{0};
        for(int i = 0; i < s.size(); i++)
            if(s[i] =='(')
                ans = max(ans, 1 + solve(i + 1, s, 1, dp));
        return ans;
    }
};