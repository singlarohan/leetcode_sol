class Solution {
public:
    int nextGreaterElement(int num) {
        string nums = to_string(num);
        int n = nums.size();
        int i = n - 2, j = n - 1;

        while(i >= 0 && nums[i] >= nums[i + 1]) i--;

        if(i < 0) return -1;
        
        while(j > i && nums[i] >= nums[j]) j--;
        
        swap(nums[i], nums[j]);

        long long ans = stoll(nums);

        return ans > INT_MAX ? -1 : ans;
    }
};