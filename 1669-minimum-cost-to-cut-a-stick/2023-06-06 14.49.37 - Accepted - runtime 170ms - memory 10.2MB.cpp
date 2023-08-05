class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, -1));
        auto solve = [&](int i, int j, int x, int y, auto &&self){
            if(x > y) return 0;
            if(dp[x][y] != -1) return dp[x][y];
            int ans = 1e9;
            for(int k = x; k <= y; k++){
                    // cout<<i <<" "<<j<<" "<<k<<endl;
                ans = min(ans, self(i, cuts[k], x, k - 1, self) + 
                               self(cuts[k], j, k + 1, y, self) + (j - i));
            }
            if(ans == 1e9) ans = 0;
            return dp[x][y] = ans;
        };
        sort(cuts.begin(), cuts.end());
        //x,y -> indices on cuts array
        return solve(0, n, 0, m - 1, solve);
    }
};