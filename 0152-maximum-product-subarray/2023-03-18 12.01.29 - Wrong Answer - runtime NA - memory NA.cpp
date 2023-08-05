class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0], negmaxi{nums[0]};
        int ans{nums[0]};
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= 0) maxi = 0, negmaxi = negmaxi*nums[i];
            maxi = max(maxi, nums[i] * maxi);
            ans = max(ans,max(maxi, negmaxi));
        }
        return ans;
    }
};