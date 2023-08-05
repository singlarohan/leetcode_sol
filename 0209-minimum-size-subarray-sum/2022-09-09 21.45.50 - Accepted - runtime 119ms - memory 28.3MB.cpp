class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l{}, r{};
        int ans{INT_MAX}, sum{};
        while(r < nums.size()){
            sum += nums[r];
            r++;
            while(sum >= target){
                ans = min(r - l, ans);
                sum -= nums[l];
                l++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};