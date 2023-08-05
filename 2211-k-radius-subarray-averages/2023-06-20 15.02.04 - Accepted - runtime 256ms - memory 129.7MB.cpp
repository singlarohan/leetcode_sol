class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        int s = 2*k + 1;
        long long curr{};
        vector<int> ans(n, -1);
        if(n < s) return ans;
        int i = 0;
        while(i < s) curr += nums[i++];
        ans[i - k - 1] = curr/s;
        for(i; i < n; i++){
            curr += nums[i] - nums[i - s];
            ans[i - k] = curr/s;
        }
        return ans;
    }
};