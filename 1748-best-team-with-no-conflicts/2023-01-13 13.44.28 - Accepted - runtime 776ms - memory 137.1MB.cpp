class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> res;
        for(int i = 0; i < ages.size(); i++)
            res.push_back({ages[i], scores[i]});
        sort(res.begin(), res.end());
        //after this LIS for 
        vector<vector<int>> dp(ages.size(), vector<int> (ages.size() + 1, -1));
        auto solve = [&](int i, int prev, auto &&self){
            if(i >= ages.size()) return 0;
            if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
            int ans{0};
            //if take
            if(prev == -1 || res[prev][1] <= res[i][1]) 
                ans = res[i][1] + self(i+1, i, self);
            //not take
            ans = max(ans, self(i+1, prev, self));
            return dp[i][prev + 1] = ans;
        };
        return solve(0, -1, solve);
    }
};