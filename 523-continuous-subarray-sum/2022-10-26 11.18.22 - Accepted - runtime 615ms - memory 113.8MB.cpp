class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // int curr;
        //Brute Force/EXTRA NAIVE
        // for(int i = 0; i < nums.size() - 1; i++){
        //     curr = nums[i] % k;
        //     for(int j = i + 1; j < nums.size(); j++){
        //         curr = (curr + nums[j]) % k;
        //         if(curr == 0)
        //         return true;
        //     }
        // }
        // return false;
        nums[0] = nums[0] % k;
        unordered_map<int, bool> mp;
        for(int i = 1; i < nums.size(); i++){
            nums[i] = (nums[i] + nums[i - 1]) % k;
            if(nums[i] == 0 || mp[nums[i]])
            return true;
            mp[nums[i - 1]] = true;
        }
        return false;
    }
};