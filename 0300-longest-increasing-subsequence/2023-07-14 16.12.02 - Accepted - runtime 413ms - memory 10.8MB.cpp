class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> req;
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n - 1; i++){
            while(i < n - 1 && nums[i + 1] <= nums[i] && nums[i + 1] > maxi) i++;
            req.push_back(nums[i]);
            maxi = max(maxi, nums[i]);
        }
        if(req.empty() || req.back() != nums.back()) 
            req.push_back(nums.back());
        
        vector<int> dp(req.size() + 1, 1);
        for(int i = 0; i < req.size(); i++){
            for(int j = 0; j < i; j++){
                if(req[i] > req[j])
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};