class Solution {
public:
    int n;

    void solve(int l, vector<vector<int>> &perms, vector<int>& nums){
        if(l == n - 1){
            perms.push_back(nums);
            return;
        }
        for(int i = l; i < n; i++){
            swap(nums[l], nums[i]);
            solve(l+1, perms, nums);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        n = nums.size();

        solve(0, perms, nums);

        return perms;
    }
};