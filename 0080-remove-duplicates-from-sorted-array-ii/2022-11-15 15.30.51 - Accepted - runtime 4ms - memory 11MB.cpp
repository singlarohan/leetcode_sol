class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count{1}, k{1};
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] !=  nums[i-1]) count = 1, nums[k++] = nums[i];
            else if(nums[i] == nums[i-1] && count < 2) count++, nums[k++] = nums[i];
            else count++;
        }
        return k;
    }
};