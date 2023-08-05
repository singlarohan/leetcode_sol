class Solution {
public:
//     int solve(int i, string s, int op_count, vector<vector<int>> &dp, int ans){
//         if(op_count == 0 && i >= s.size())
//             return ans;
//         if(i >= s.size() || op_count < 0)
//             return INT_MIN;
//         //choose
//         if(dp[i][op_count] != -1)
//             return dp[i][op_count];
//         int ch_op{INT_MIN}, ch_cl{INT_MIN};
//         if(s[i] == '(')
//             ch_op = solve(i+1, s, op_count + 1, dp, ans + 1);
//         else
//             ch_cl = solve(i+1, s, op_count - 1, dp, ans + 1);
//         if(op_count == 0)
//         return dp[i][op_count] = max(ans, max(ch_op, max(ch_cl, solve(i + 1, s, 0, dp, 0))));
//         else
//         return dp[i][op_count] = max(ch_op, max(ch_cl, solve(i + 1, s, 0, dp, 0)));

//     }
    //THIS IS FOR SUBSEQUENCE FUCK!
    // int solve(int i, string &s, int op_count, vector<vector<int>> &dp){
    //     if(i >= s.size())
    //         return -op_count;
    //     if(dp[i][op_count] != -1)
    //         return dp[i][op_count];
    //     int ch_cl{}, ch_op{}, nch{};
    //     if(op_count > 0 && s[i] == ')')
    //         ch_cl = 1 + solve(i + 1, s, op_count - 1, dp);
    //     if(s[i] == '(')
    //     ch_op = 1 + solve(i + 1, s, op_count + 1, dp);
    //     else if(op_count == 0)
    //         nch = solve(i + 1, s, op_count, dp);
    //     return dp[i][op_count] = max(ch_cl, max(ch_op, nch));
    // }
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