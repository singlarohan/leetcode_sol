class Solution {
public:
    //total number of arithmetic subarrays is given by
    //n(n+1)/2, n = number of elements in subarray - 2
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() <= 2)
        return 0;
        int ans{};
        int currlen{0}, currDiff = nums[1] - nums[0];
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == currDiff)
                currlen++;
            else{
                ans += (currlen*(currlen + 1)) / 2;
                currDiff = nums[i] - nums[i-1];
                currlen = 0;
            }
        }
        ans += (currlen*(currlen + 1)) / 2;
        return ans;
    }
};