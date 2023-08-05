class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int curr{0};
        for(int i = 0; i < k; i++)
            curr += nums[i];
        int maxval = curr, maxind = 0;
        for(int i = k; i < nums.size(); i++){
            curr += nums[i] - nums[i-k];
            if(curr > maxval)
                maxind = i - k + 1;
        }
        vector<int> ans;
        for(int i = maxind; i < maxind + k; i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};