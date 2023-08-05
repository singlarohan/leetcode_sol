class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >=0 && nums[i] > nums[i+1])
            i--;
        if(i < 0){
            sort(nums.begin(), nums.end());
            return;
        }
        swap(nums[i], nums[i+1]);
        while(++i < nums.size() - 1 && nums[i] > nums[i+1])
            swap(nums[i], nums[i+1]);
        return;
    }
};