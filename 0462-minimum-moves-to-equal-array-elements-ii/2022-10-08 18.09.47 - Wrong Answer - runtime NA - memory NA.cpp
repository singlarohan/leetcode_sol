class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mean = accumulate(nums.begin(), nums.end(), 0)/nums.size();
        int ans{};
        for(auto &x:nums)
        ans += abs(mean - x);
        return ans;
    }
};