class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(string text1, string text2, int i, int j){
        if(i >= text1.size() || j >= text2.size())
            return 0;
        int ans{};
        if(dp[i][j] != -1)
            return dp[i][j];
        for(int k = i; k < text1.size(); k++)
            for(int l = j; l < text2.size(); l++)
                if(text1[k] == text2[l])
                    ans = max(ans, 1 + solve(text1, text2, k + 1, l + 1));
        return dp[i][j] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        dp = vector<vector<int>> (text1.size(), vector<int> (text2.size(), -1));
        // memset(dp, -1, sizeof(dp));
        return solve(text1, text2, 0, 0);
    }
};