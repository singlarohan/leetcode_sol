class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans{};
        long long count{};
        int i{};
        while(i < nums.size()){
            if(nums[i] == 0) {
                count++;
                ans += count;
            }
            else{
                // ans += (count * (count + 1))/2;
                count = 0;
            }
            i++;
        }
        // ans += (count * (count + 1))/2;
        // ans += count;
        return ans;
    }
};