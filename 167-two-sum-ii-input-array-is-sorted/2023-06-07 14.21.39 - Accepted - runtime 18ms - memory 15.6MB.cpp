class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans;

        while(left < right){
            if(nums[left] + nums[right] == target){
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
            else if(nums[left] + nums[right] < target) left++;
            else right--;
        }
        return ans;
    }
};