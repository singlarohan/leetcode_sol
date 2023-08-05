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
    
    void solve2(int i, vector<int> &nums, vector<int> &temp){
        ans.push_back(temp);
        if(i >= nums.size())
            return;
        for(int j = i; j < nums.size(); j++){
            temp.push_back(nums[j]);
            solve2(j+1, nums, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        // ans.push_back(temp);
        solve2(0, nums, temp);
        return ans;   
    }
};