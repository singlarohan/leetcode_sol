class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, 0));
        sort(cuts.begin(), cuts.end());
        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(i > j) continue;
                int cost = 1e9;
                for(int k = i; k <= j; k++){
                    cost = min(cost,(j + 1 < m ? cuts[j + 1] : n) 
                                  - (i - 1 >= 0 ? cuts[i - 1] : 0)
                                        + dp[i][k] + dp[k + 1][j + 1]);
                }
                dp[i][j + 1] = cost;
            }
        }
        return dp[0][m];
    }
};