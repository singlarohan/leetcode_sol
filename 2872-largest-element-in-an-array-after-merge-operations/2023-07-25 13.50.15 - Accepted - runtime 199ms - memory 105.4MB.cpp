class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans = 0, curr = nums.back();
        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i - 1] <= curr)
                curr += nums[i - 1];
            else{
                ans = max(curr, ans);
                curr = nums[i - 1];
            }
        }
        ans = max(curr, ans);
        return max((long long)nums[0], ans);
    }
};