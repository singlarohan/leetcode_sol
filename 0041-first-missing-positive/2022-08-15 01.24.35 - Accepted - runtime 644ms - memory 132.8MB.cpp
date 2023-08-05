class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int i =0; i < nums.size(); i++){
            mp[nums[i]] = true;
            
        }
        int i{1};
        for(i = 1; ; i++){
            if(!mp[i])
                break;
        }
        return i;
    }
};