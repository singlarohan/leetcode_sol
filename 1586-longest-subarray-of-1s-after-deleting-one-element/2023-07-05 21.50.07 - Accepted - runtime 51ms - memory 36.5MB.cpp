class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev{}, curr{};
        int ans = 0;
        bool zero = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans = max(ans, prev + curr);
                prev = curr;
                curr = 0;
                zero = false;
                continue;
            }
            curr++;
        }
        return ans > prev + curr ? ans : prev + curr - zero;
    }
};