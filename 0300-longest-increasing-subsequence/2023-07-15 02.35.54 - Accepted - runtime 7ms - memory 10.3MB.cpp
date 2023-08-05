class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        
        int get_idx;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                get_idx = lower_bound(begin(ans), end(ans), nums[i]) - begin(ans); 
                // WHY ?? remember we want [1,2,3... increasing sequence]
                ans[get_idx] = nums[i];
            }
        }
        return ans.size();
    }
};