class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int mean = accumulate(nums.begin(), nums.end(), 0)/nums.size();
        int ans{}, ans2{};
        int median;
        int n = nums.size();
        if(n % 2) median = nums[n / 2];
        else median = (nums[n / 2] + nums[n / 2 - 1]) / 2;
        for(auto &x:nums)
            ans += abs(x - median);
        return ans;
    }
};