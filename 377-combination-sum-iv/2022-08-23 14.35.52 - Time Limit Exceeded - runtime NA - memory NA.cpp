class Solution {
public:
    int solve(int i, vector<int> & nums, int target){
        if(target == 0)
            return 1;        
        if(target < 0 || i >= nums.size())
            return 0;
        int ans{0};
        for(int j = i; j<nums.size(); j++)
            ans += solve(i, nums, target - nums[j]);
        return ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};