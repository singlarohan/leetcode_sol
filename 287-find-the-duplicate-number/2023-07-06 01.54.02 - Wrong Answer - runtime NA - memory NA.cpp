class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size() - 1;
        return sum - (n*(n + 1))/2;
    }
};