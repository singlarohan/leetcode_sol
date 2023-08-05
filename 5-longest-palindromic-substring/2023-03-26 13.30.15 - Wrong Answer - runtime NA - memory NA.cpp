class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int x{}, y{};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j - 1];
                    if(dp[i][j] > dp[x][y])
                        x = i, y = j;
                }
                // else dp[i][j] = 0;
            }
        }
        string ans;
        int size = dp[x][y];
        while(size--){
            ans += s[x - 1];
            x--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};