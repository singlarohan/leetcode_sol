class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        //curr stores current length of array where gcd == 3

        int len{}, curr_gcd{1}, ans{};
        for(int i = 0; i < nums.size(); i++){
            curr_gcd = __gcd(nums[i], curr_gcd);
            if(curr_gcd % k != 0){
                curr_gcd = nums[i];
                len = 0;
            }
            if(curr_gcd % k == 0){
                len++;
                if(curr_gcd == k)
                    ans += len;
            }
        }
        return ans;
    }
};