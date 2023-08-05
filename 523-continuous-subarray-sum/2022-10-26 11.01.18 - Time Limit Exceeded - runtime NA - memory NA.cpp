class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int curr;
        for(int i = 0; i < nums.size() - 1; i++){
            curr = nums[i] % k;
            for(int j = i + 1; j < nums.size(); j++){
                curr = (curr + nums[j]) % k;
                if(curr == 0)
                return true;
            }
        }
        return false;
    }
};