class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int maxi{};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j - 1];
                    maxi = max(maxi, dp[i][j]);
                }
                // else dp[i][j] = 0;
            }
        }
        string ans;
        int i = n, j = n;
        while(i > 0 && j > 0){
            if(s[i - 1] == s2[j - 1]){
                ans += s[i - 1];
                i--, j--;
            }
            else if(dp[i][j - 1] > dp[i - 1][j])
                j--;
            else i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};