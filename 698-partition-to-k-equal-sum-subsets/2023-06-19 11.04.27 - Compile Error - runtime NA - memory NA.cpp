class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total % k != 0) return 0;
        int target = total / k;
        auto solve
        return solve(0, 0, solve);
    }
};