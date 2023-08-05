class Solution {
public:
    int solve(int target, int i, vector<int> &nums, int &ans){
        if(target == 0 && i == nums.size())
            return 1;
        if(i >= nums.size())
            return 0;
        //inserting minus
        int m = solve(target + nums[i], i+1, nums, ans);
        //inserting plus
        int p = solve(target - nums[i], i+1, nums, ans);
        return m+p;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans{};
        return solve(target, 0, nums, ans);
    }
};