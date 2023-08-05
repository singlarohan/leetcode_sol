class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i > j) return 0;

            if(dp[i][j] != -1) return dp[i][j];
            
            int cost = 1e9;

            for(int k = i; k <= j; k++){
                cost = min(cost,(j + 1 < m ? cuts[j + 1] : n) - (i - 1 >= 0 ? cuts[i - 1]:0)
                                    + self(i, k - 1, self) + self(k + 1, j, self));
            }
            return dp[i][j] = cost;
        };
        sort(cuts.begin(), cuts.end());
        //x,y -> indices on cuts array
        return solve(0, m - 1, solve);
    }
};