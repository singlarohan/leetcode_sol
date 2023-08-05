class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = max(nums[0], nums[1]), maxi2 = min(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            if(maxi1 <= nums[i]){
                maxi2 = maxi1;
                maxi1 = nums[i];
            }
            else if(maxi2 <= nums[i]) maxi2 = nums[i];
        }
        return (maxi2 - 1) * (maxi1 - 1);
    }
};