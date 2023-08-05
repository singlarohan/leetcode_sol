class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //common subsequence in s and rev(s)
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<int> dp(n + 1, 0);
        vector<int> prev(n + 1, 0);
        int maxi{};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s2[j - 1]){
                    dp[j] = 1 + prev[j - 1];
                    maxi = max(maxi, dp[j]);
                }
                else dp[j] = max(prev[j], dp[j - 1]);
            }
            prev = dp;
        }
        return maxi;
    }
};