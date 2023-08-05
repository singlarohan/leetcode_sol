class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = words.size(), n = words[0].size();
        int t = target.size();
        int M = 1e9 + 7;

        vector<vector<int>> dp(n+1, vector<int> (t+1, -1));
        vector<vector<int>> count(n, vector<int> (26, 0));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                count[j][words[i][j] - 'a']++;

        auto solve = [&](int i, int curr, auto &&self){
            if(curr == t) return 1;
            if(i >= n) return 0;
            if(dp[i][curr] != -1) return dp[i][curr];

            long long ans{};
            if(count[i][target[curr] - 'a'] != 0)
                ans += (long long)count[i][target[curr] -'a'] * self(i + 1, curr + 1, self);

            ans += self(i + 1, curr, self);
            
            return dp[i][curr] = ans % M;
        };

        return solve(0, 0, solve);
    }
};