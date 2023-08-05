class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
    
        for(int i = 0; i < nums.size(); i++){
            if(ans.empty() || nums[i] > ans.back()) ans.push_back(nums[i]);
            
            else *lower_bound(ans.begin(), ans.end(), nums[i]) = nums[i];
        }
        return ans.size();
    }
};