class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i<nums.size(); i++){
        //     if(i != nums[i])
        //         return i;
        // }
        // return nums.size();
        
        // O(N) complexity
        int sum{};
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++)
            sum += nums[i];
        int ans = n*(n+1)/2;
        return ans - sum;
    }
};