class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //in O(1)
        int n = nums.size();
        vector<int> ans(n, 1);

        int pref{1}, suff{1};
        for(int i = 1; i < n; i++){
            ans[i] *= nums[i - 1] * pref;
            pref *= nums[i - 1];

            ans[n - i - 1] *= nums[n - i] * suff;
            suff *= nums[n - i];
        }
        
        return ans;
    }
};