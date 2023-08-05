class Solution {
public:
    vector<vector<int>> ans;
    int n, full;

    void solve(vector<int> &nums, int mask, vector<int> &temp){
        if(mask == full){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) == 0){
                temp.push_back(nums[i]);
                solve(nums, mask | (1 << i), temp);
                temp.pop_back();
            }
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        full = (1 << n) - 1;
        
        vector<int> temp;
        
        solve(nums, 0, temp);

        return ans;
    }
};