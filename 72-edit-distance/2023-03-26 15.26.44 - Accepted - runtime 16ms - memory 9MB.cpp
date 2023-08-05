class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(int i, int j, string &word1, string &word2){
        if(j >= word2.size())
            return word1.size() - i;
        if(i >= word1.size())
            return word2.size() - j;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(word1[i] != word2[j]){
            //if insert
            int a = solve(i, j + 1, word1, word2);
            //if replace
            int b = solve(i+1, j + 1, word1, word2);
            //if remove
            int c = solve(i+1, j, word1, word2);
            return dp[i][j] = 1 + min(a,min(b,c));
        }
        else
            return dp[i][j] = solve(i + 1, j + 1, word1, word2);
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < m + 1; i++) dp[i][n] = m - i;
        for(int i = 0; i < n + 1; i++) dp[m][i] = n - i;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(word1[i] != word2[j]){
                    //if insert
                    int a = dp[i][j + 1];
                    //if replace
                    int b = dp[i + 1][j + 1];
                    //if remove
                    int c = dp[i + 1][j];
                    dp[i][j] = 1 + min(a,min(b,c));
                }
                else dp[i][j] = dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
        // return solve(0, 0, word1, word2);
    }
};