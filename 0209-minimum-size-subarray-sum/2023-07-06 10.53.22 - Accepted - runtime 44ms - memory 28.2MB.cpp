class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int curr = 0, ans = INT_MAX;

        for(r = 0; r < nums.size(); r++){
            curr += nums[r];

            while(curr >= target){
                ans = min(ans, r - l + 1);
                curr -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};