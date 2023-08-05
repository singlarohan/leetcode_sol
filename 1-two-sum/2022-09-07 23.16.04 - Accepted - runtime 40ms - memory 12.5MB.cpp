class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i< nums.size(); i++)
            mp[nums[i]] = i + 1;
        for(int i = 0; i < nums.size(); i++){
            int j = mp[target - nums[i]];
            if(j && j != i + 1)
                return {i,j - 1};
        }
        return {0,1};
    }
};