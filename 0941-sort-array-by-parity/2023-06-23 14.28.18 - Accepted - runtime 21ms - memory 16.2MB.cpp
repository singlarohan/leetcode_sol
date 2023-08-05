class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0; 
        int r = nums.size() - 1;

        while(l < r && nums[l] % 2 == 0) l++;
        while(l < r && nums[r] % 2 != 0) r--;

        while(l < r){
            swap(nums[l], nums[r]);
            l++, r--;

            while(l < r && nums[l] % 2 == 0) l++;
            while(l < r && nums[r] % 2 != 0) r--;
        }
        return nums;
    }
};