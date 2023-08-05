class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            if(nums[r] + nums[l] == target)
                break;
            if(nums[r] + nums[l] > target)
                r--;
            else if(nums[l] + nums[r] < target)
                l++;
        }
        return {l+1, r+1};
    }
};