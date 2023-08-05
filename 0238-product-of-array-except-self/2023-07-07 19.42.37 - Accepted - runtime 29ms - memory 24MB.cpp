class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //in O(1)
        vector<int> ans(nums.size(), 1);

        int pref{1};
        for(int i = 1; i < nums.size(); i++){
            ans[i] = nums[i - 1] * pref;
            pref *= nums[i - 1];
        } 
        
        int suff{1};
        for(int i = nums.size() - 2; i >= 0; i--){
            ans[i] = ans[i] * nums[i + 1] * suff;
            suff *= nums[i + 1];
        }
        
        return ans;
    }
};