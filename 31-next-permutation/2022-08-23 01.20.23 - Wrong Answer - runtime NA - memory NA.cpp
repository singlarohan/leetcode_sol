class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2, j = nums.size() - 1;
        while(i >=0 && nums[i] > nums[i+1])
            i--;
        if(i >= 0){
            while(j > i && nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());
        return;
        // if(i < 0){
        //     sort(nums.begin(), nums.end());
        //     return;
        // }
        // swap(nums[i], nums[j]);
        // i++, j++;
        // while(j < nums.size() && nums[i] >= nums[j]){
        //     swap(nums[i], nums[j]);
        //     i++, j++;
        // }
        // return;
    }
};