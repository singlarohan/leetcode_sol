class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int> &nums, int l){
        if(l == n - 1){
            ans.push_back(nums);
        }
        for(int i = l; i < n; i++){
            if(i == l || nums[i] != nums[l]){
                swap(nums[i], nums[l]);
                solve(nums, l + 1);
                swap(nums[i], nums[l]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        solve(nums, 0);
        return ans;
    }
};