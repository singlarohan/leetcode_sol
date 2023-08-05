class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool flag{};
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                flag = true;
                swap(nums[i], nums[i - 1]);
                break;
            }
        }
        if(!flag) reverse(nums.begin(), nums.end());
    }
};