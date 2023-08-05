class Solution {
public:
    int minDistance(string word1, string word2) {
        //n + m - 2 * size(lcs)
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1, 0);
        vector<int> prev(m + 1, 0);
        int maxi{};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[j] = 1 + prev[j - 1];
                    maxi = max(maxi, dp[j]);
                }
                else dp[j] = max(dp[j - 1], prev[j]);
            }
            prev = dp;
        }
        return n + m - 2 * maxi;
    }
};