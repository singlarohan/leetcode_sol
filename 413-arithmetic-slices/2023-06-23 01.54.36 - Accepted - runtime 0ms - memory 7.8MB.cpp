class Solution {
private:
    unordered_map<int, int> mp;
public:
    int solve(int i, int curr_diff, vector<int> &nums){
        if(i >= nums.size()) return 0;

        if(mp.find(i) != mp.end())
            return mp[i];

        int ans{};

        if(i + 1 < nums.size() && nums[i + 1] - nums[i] == curr_diff)
        ans = 1 + solve(i + 1, curr_diff, nums);

        return mp[i] = ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans{};
        for(int i = 1; i < nums.size() - 1; i++){
            ans += solve(i, nums[i] - nums[i-1], nums);
        }   
        return ans;
    }
};