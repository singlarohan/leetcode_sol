class Solution {
public:
    void solve(int l, int r, vector<vector<int>> &perms, vector<int>& nums){
        if(l == r){
            perms.push_back(nums);
            return;
        }
        for(int i = l; i<=r; i++){
            swap(nums[l], nums[i]);
            solve(l+1,r, perms, nums);
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        solve(0, nums.size() - 1, perms, nums);
        return perms;
    }
};