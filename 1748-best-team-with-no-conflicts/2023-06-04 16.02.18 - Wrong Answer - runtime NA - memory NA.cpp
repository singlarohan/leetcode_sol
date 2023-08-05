class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> res;
        for(int i = 0; i < ages.size(); i++)
            res.push_back({ages[i], scores[i]});
        sort(res.begin(), res.end());
        //after this LIS for 
        // vector<vector<int>> dp(ages.size() + 1, vector<int> (ages.size() + 1, 0));
        // auto solve = [&](int i, int prev, auto &&self){
        //     if(i >= ages.size()) return 0;
        //     if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        //     int ans{0};
        //     //if take
        //     if(prev == -1 || res[prev][1] <= res[i][1]) 
        //         ans = res[i][1] + self(i+1, i, self);
        //     //not take
        //     ans = max(ans, self(i+1, prev, self));
        //     return dp[i][prev + 1] = ans;
        // };
        //Tabulation
        // for(int i = ages.size() - 1; i >= 0; i--){
        //     for(int prev = i-1; prev >= -1; prev--){
        //         int nottake = dp[i+1][prev+1];
        //         int take = 0;
        //         if(prev == -1 || res[prev][1] <= res[i][1])
        //             take = res[i][1] + dp[i+1][i+1];
        //         dp[i][prev + 1] = max(take, nottake);
        //     }
        // }
        // return dp[0][-1+1];
        //BEST
        int n = ages.size();
        int maxi{};
        vector<int> dp(n);
        for(int i = 0; i < n; i++) dp[i] = res[i][1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(res[i][1] >= res[j][1])
                dp[i] = max(dp[i], res[i][1] + dp[j]);
                maxi = max(maxi, dp[i]);
            }
        }
        return maxi;
        // return solve(0, -1, solve);
    }
};