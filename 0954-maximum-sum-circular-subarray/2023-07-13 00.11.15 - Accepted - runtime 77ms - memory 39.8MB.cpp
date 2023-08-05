class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_sub = INT_MAX, curr_sub = 0;
        int max_sub = INT_MIN, curr2 = 0;
        int total = 0, maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(curr_sub > 0) curr_sub = 0;
            curr_sub += nums[i];
            min_sub = min(curr_sub, min_sub);

            if(curr2 < 0) curr2 = 0;
            curr2 += nums[i];
            max_sub = max(curr2, max_sub);

            maxi = max(maxi, nums[i]);
            total += nums[i];
        }
        return maxi < 0 ? maxi : max(max_sub, total - min_sub);
    }
};