class Solution {
public:
    int helper(unordered_map<int, int> &mp, int i){
        if(mp[i] == 0 || mp[i] > 1) return mp[i];
        else return 1 + helper(mp, i - 1);
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans{};
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = 1;
        for(int i = 0; i < nums.size(); i++)
            ans = max(ans, helper(mp, nums[i]));
        return ans;
    }
};