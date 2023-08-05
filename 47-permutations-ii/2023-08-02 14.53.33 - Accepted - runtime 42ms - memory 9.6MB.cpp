class Solution {
public:
    set<vector<int>> s;
    void solve( int i, vector<int>& nums){
        if(i >= nums.size()){
            s.insert(nums);
            return;
        }
        //ifchoose
        for(int j = i; j < nums.size(); j++){
            swap(nums[j], nums[i]);
            solve(i + 1, nums);
            swap(nums[j], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums);
        vector<vector<int>> ans;
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};