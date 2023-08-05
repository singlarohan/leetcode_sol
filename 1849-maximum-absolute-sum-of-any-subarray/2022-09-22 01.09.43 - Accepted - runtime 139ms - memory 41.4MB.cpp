class Solution {
public:
    //using dp
    
    // int dp[100000];
    
    // int solve(int i, vector<int> & nums){
    //     if(i >= nums.size())
    //         return 0;
    //     if(dp[i] != -1)
    //         return dp[i];
    //     int ans{};
    //     ans = max(ans, nums[i] + solve(i+1, nums));
    //     return dp[i] = ans;
    // }
    
    int maxAbsoluteSum(vector<int>& nums) {
        //using dp
//         memset(dp, -1, sizeof(dp));
//         int ans{INT_MIN};
//         for(int i = 0; i < nums.size(); i++){
//             ans = max(ans, solve(i, nums));
//             nums[i] = -nums[i];
//         }
//         memset(dp, -1, sizeof(dp));
//         for(int i = 0; i < nums.size(); i++)
//             ans = max(ans, solve(i, nums));
//         return ans;
        
        //using kadene's prefix
        int maxPosSum{};
        int curr{};
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            maxPosSum = max(curr, maxPosSum);
            if(curr < 0)
                curr = 0;
        }
        int maxNegSum{};
        curr = 0;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            maxNegSum = min(curr, maxNegSum);
            if(curr > 0)
                curr = 0;
        }
        return max(maxPosSum, abs(maxNegSum));
    }
};