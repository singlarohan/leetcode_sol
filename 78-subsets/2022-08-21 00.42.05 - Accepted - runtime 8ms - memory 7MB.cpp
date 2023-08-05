class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i, vector<int> &nums, vector<int> &temp){
        if(i >= nums.size())
            return;
        //ifchoose
        temp.push_back(nums[i]);
        ans.push_back(temp);
        solve(i+1, nums, temp);
        temp.pop_back();
        //not choose
        solve(i+1, nums, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        ans.push_back(temp);
        solve(0, nums, temp);
        return ans;   
    }
};