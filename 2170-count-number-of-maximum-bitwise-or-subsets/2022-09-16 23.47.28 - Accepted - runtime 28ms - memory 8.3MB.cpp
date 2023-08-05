class Solution {
public:
    int solve(int i, int maxi, vector<int> &nums, int curr){
        if(i >= nums.size())
            return curr == maxi;
        int ans{};
        if(curr == maxi)
            ans = 1;
        for(int j = i; j < nums.size(); j++)
            ans += solve(j + 1, maxi, nums, curr | nums[j]);
        return ans;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi{};
        for(int i = 0; i < nums.size(); i++)
            maxi = maxi | nums[i];
        return solve(0, maxi, nums, 0);
    }
};