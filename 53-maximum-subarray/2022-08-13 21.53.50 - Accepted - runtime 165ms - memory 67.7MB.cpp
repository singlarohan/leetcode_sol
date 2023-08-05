class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best{nums[0]},maxi{nums[0]};
        for(int i = 1; i<nums.size(); i++){
            maxi = max(maxi + nums[i], nums[i]);
            best = max(maxi, best);
        }
        return best;
    }
};