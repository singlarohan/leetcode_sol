class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp){
        ans.push_back(temp);
        if(i >= nums.size())
            return;
        for(int j = i; j < nums.size(); j++){
            temp.push_back(nums[j]);
            solve(j + 1, nums, ans, temp);
            temp.pop_back();
            while(j + 1 < nums.size() && nums[j+1] == nums[j])
                j++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, ans, temp);
        return ans;
    }
};