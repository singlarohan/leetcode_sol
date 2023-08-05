class Solution {
public:
    int solve(int i, string s, int op_count, vector<vector<int>> &dp, int ans){
        if(op_count == 0 && i >= s.size())
            return ans;
        if(i >= s.size() || op_count < 0)
            return INT_MIN;
        //choose
        if(dp[i][op_count] != -1)
            return dp[i][op_count];
        int ch_op{INT_MIN}, ch_cl{INT_MIN};
        if(s[i] == '(')
            ch_op = solve(i+1, s, op_count + 1, dp, ans + 1);
        else
            ch_cl = solve(i+1, s, op_count - 1, dp, ans + 1);
        if(op_count == 0)
        return dp[i][op_count] = max(ans, max(ch_op, max(ch_cl, solve(i + 1, s, 0, dp, 0))));
        else
        return dp[i][op_count] = max(ch_op, max(ch_cl, solve(i + 1, s, 0, dp, 0)));

    }
    
    int longestValidParentheses(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size() + 1, -1));
        return solve(0, s, 0, dp, 0);
    }
};