class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_sub = INT_MAX, currm_sub = 0;
        int max_sub = INT_MIN, currM_sub = 0;
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            currm_sub += nums[i];
            min_sub = min(currm_sub, min_sub);
            if(currm_sub > 0) currm_sub = 0;

            currM_sub += nums[i];
            max_sub = max(currM_sub, max_sub);
            if(currM_sub < 0) currM_sub = 0;

            total += nums[i];
        }
        return max_sub < 0 ? max_sub : max(max_sub, total - min_sub);
    }
};