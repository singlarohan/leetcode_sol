class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i == j) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            int ans = 1e9;
            for(auto k: cuts){
                if(k > i && k < j){
                    // cout<<i <<" "<<j<<" "<<k<<endl;
                    ans = min(ans, self(i, k, self) + self(k, j, self) + (j - i));
                }
            }
            if(ans == 1e9) ans = 0;
            return dp[i][j] = ans;
        };
        return solve(0, n, solve);
    }
};