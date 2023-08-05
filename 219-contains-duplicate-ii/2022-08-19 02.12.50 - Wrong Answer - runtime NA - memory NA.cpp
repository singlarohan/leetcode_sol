class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;
        for(int i = 0; i<nums.size(); i++){
            if(mp[nums[i]])
                return true;
            mp[nums[i]] = true;
        }
        return false;
    }
};