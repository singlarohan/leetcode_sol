class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> dp(points.size(), vector<long long> (points[0].size(), -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i == points.size())
                return (long long)0;
            if(dp[i][j] != -1)
            return dp[i][j];
            long long ans{};
            for(int k = 0; k < points[0].size(); k++)
                ans = max(ans, (-abs(k - j) + self(i + 1, k, self)));
            return dp[i][j] = points[i][j] + ans;
        };
        long long ans{};
        for(int j = 0; j < points[0].size(); j++)
            ans = max(ans, solve(0, j, solve));
        return ans;
    }
};