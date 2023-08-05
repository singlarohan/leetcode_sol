class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = true;
        long long ans{};
        for(int i = 1;  k; i++){
            if(!mp[i])
                ans += i, k--;
        }
        return ans;
    }
};