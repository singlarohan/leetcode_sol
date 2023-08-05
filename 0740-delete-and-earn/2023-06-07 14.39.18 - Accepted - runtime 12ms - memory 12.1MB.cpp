class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = nums.size();
        int n = *max_element(nums.begin(), nums.end()) + 1;
        
        vector<int> hash(n, 0);
        vector<int> dp(n, -1);

        for(auto x:nums) hash[x]++;
        //now it's a simple take not take question
        auto solve = [&](int i, auto &&self){
            if(i >= n) return 0;
            if(dp[i] != -1) return dp[i];

            int take = i*hash[i] + self(i + 2, self);
            int nottake = self(i + 1, self);
            return dp[i] = max(take, nottake);
        };
        return solve(1, solve);
    }
};