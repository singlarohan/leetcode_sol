class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //in O(1)
        vector<int> pref(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            pref[i] = nums[i - 1] * pref[i - 1];
        
        int suff{1};
        for(int i = nums.size() - 2; i >= 0; i--){
            pref[i] = pref[i] * nums[i + 1] * suff;
            suff *= nums[i + 1];
        }
        
        // vector<int> ans(nums.size(), 0);
        // for(int i = 0; i < nums.size(); i++)
        //     ans[i] = pref[i] * suff[i];

        return pref;
    }
};