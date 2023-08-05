class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int thresh) {
        int l{-1};
        int maxi{};
        for(int i = 0; i < nums.size(); i++){
            if(l == -1){
                l = nums[i] % 2 == 0 ? i : -1;
                continue;
            }
            else if(nums[i] % 2 == nums[i - 1] % 2){
                maxi = max(maxi, (i - l));
                l = nums[i] % 2 == 0 ? -1 : i;
            }
            else if(nums[i] > thresh){
                maxi = max(maxi, (i - l));
                l = -1;
            }
        }
        if(l != -1) maxi = max(maxi, (int)nums.size() - l);
        return maxi;
    }
};