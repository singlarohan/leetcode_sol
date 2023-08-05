class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) nums.back();
        int maxi = nums[0], negmaxi{nums[0]};
        int ans{nums[0]};
        for(int i = 1; i < nums.size(); i++){
            // if(nums[i] == 0) maxi = 0;
            maxi = max(nums[i], nums[i] * maxi);
            if(negmaxi == 0) negmaxi = nums[i];
            else negmaxi = negmaxi*nums[i];
            ans = max(ans,max(maxi, negmaxi));
        }
        maxi = nums.back(), negmaxi = nums.back();
        for(int i = nums.size() - 2; i >= 0; i--){
            // if(nums[i] == 0) maxi = 0;
            maxi = max(nums[i], nums[i] * maxi);
            if(negmaxi == 0) negmaxi = nums[i];
            else negmaxi = negmaxi*nums[i];
            ans = max(ans,max(maxi, negmaxi));
        }
        return ans;
    }
};