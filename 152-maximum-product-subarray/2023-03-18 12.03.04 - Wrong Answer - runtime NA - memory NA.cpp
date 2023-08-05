class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0], negmaxi{nums[0]};
        int ans{nums[0]};
        for(int i = 1; i < nums.size(); i++){
            // if(nums[i] == 0) maxi = 0;
            maxi = max(nums[i], nums[i] * maxi);
            negmaxi = negmaxi*nums[i];
            ans = max(ans,max(maxi, negmaxi));
        }
        return ans;
    }
};