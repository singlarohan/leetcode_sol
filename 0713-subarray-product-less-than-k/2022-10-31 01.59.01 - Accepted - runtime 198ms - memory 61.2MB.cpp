class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0)
            return 0;
        int i{}, j{}, ans{};
        int prod{1};
        while(j < nums.size()){
            prod *= nums[j];
            j++;
            while(i < j && prod >= k)
                prod /= nums[i++];
            ans += j - i;
        }
        return ans;
    }
};