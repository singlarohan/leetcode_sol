class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr{1};
        for(int i = 1; i < nums.size(); i++){
            while(nums[i] == nums[i-1])
                i++;
            nums[curr++] = nums[i];
        }
        return curr;
    }
};