class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int curr{}, sum{};
        for(int i = 0; i < nums.size(); i++)
            curr += i * nums[i], sum += nums[i];
        int maxi = curr;
        int n = nums.size();
        for(int k = 1; k < n; k++){
            curr = curr + sum - nums[n - k] * (n);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};
