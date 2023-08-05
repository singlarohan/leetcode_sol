class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        auto solve = [&](int i, int j, auto &&self) -> int{
            if(i >= m || j >= n) return max(n - j, m - i);
            if(dp[i][j] != -1) return dp[i][j];

            if(word1[i] == word2[j])
                return dp[i][j] = self(i + 1, j + 1, self);
            else{
                int ans{INT_MAX};
                //if insert
                ans = min(ans, 1 + self(i, j + 1, self));
                //if delete
                ans = min(ans, 1 + self(i + 1, j, self));
                //if replace
                ans = min(ans, 1 + self(i + 1, j + 1, self));
                return dp[i][j] = ans;
            }
        };
        return solve(0, 0, solve);
    }
};