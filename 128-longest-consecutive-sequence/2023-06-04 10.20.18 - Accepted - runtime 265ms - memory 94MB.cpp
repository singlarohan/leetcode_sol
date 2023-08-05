class Solution {
public:
    int helper(unordered_map<int, int> &mp, int i){
        if(mp[i] == 0 || mp[i] > 1)
            return mp[i];
        return mp[i] = 1 + helper(mp, i-1);
    }
    
    int longestConsecutive(vector<int>& nums) {
        int ans{};
        unordered_map<int, int> mp;
        for(int i = 0; i< nums.size(); i++)
            mp[nums[i]] = 1;
        for(int i = 0; i< nums.size(); i++)
            ans = max(ans, helper(mp, nums[i]));
        return ans;
    }
};