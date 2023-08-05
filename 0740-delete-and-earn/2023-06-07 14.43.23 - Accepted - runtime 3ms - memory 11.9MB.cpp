class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = nums.size();
        int n = *max_element(nums.begin(), nums.end()) + 1;
        
        vector<int> hash(n, 0);
        // vector<int> dp(n, -1);

        for(auto x:nums) hash[x]++;

        //now it's a simple take not take question

        //MEMOIZATION
        // auto solve = [&](int i, auto &&self){
        //     if(i >= n) return 0;
        //     if(dp[i] != -1) return dp[i];

        //     int take = i*hash[i] + self(i + 2, self);
        //     int nottake = self(i + 1, self);
        //     return dp[i] = max(take, nottake);
        // };
        // return solve(1, solve);

        //TABULATION
        vector<int> dp(n + 2, -1);
        dp[n] = 0, dp[n + 1] = 0;
        for(int i = n - 1; i >= 0; i--){
            dp[i] = max(dp[i+1], i*hash[i] + dp[i+2]);
        }
        return dp[1];
    }
};