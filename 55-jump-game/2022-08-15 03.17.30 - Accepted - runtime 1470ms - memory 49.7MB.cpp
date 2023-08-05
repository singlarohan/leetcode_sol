class Solution {
public:
//     bool solve(int i, vector<int> &nums, vector<int> &dp){
//         if(i>= nums.size() || (i != nums.size() - 1 && nums[i] == 0))
//             return false;
//         if(i == nums.size() - 1)
//             return true;
//         if(dp[i]!= -1)
//             return dp[i];
//         bool ans = false;
//         for(int j = 1; j<= nums[i]; j++){
//             dp[i] = dp[i] || solve(i+j, nums, dp);
//         }
//         return dp[i];
//     }
    
//     bool canJump(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return solve(0, nums, dp);
//     }
// };
    int dp[(int)1e5+10];

    bool solve(int i,int size,vector<int>& nums){

        if(i >= size) return true;
        if(dp[i] != -1) return dp[i];
        int mx = nums[i];
        int ans = false;
        for(int j=1;j<=mx;j++){
            ans = ans || solve(i+j,size,nums);
        }
        return dp[i] = ans;

    }

    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums.size()-1,nums);
    }
};
