class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr{}, maxi{INT_MIN};
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            maxi = max(maxi, curr);
            if(curr < 0) curr = 0;
        }
        return maxi;
    }
};