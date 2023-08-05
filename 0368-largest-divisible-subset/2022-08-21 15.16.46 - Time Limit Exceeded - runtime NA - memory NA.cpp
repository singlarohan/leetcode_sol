class Solution {
public:
    unordered_map<int, int> mp;

    void solve(int i, vector<int>& nums, vector<int>& temp, vector<int>& ans){
        if(i >= nums.size()){
            if(temp.size() > ans.size())
                ans = temp;
            return;
        }
        //choose
        if(!temp.empty() && mp[temp.back()] > temp.size())
            return;
        if(temp.empty() || nums[i] % temp.back() == 0){
            if(mp[nums[i]] <= temp.size()){
                mp[nums[i]] = temp.size();
                temp.push_back(nums[i]);
                solve(i+1, nums, temp, ans);
                temp.pop_back();
            }
        }
        solve(i+1, nums, temp, ans);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> temp;
        solve(0, nums, temp, ans);
        return ans;
    }
};