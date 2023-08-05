class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans{};
        int count{};
        int i{};
        while(i < nums.size()){
            if(nums[i++] == 0) {
                count++;
                ans += count;
            }
            else count = 0;
        }
        return ans;
    }
};