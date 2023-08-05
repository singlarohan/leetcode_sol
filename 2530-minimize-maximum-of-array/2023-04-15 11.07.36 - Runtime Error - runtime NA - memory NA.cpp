class Solution {
public:
    bool isValid(vector<int> &nums, int maxi){
        int count{};
        for(int i = nums.size() - 1; i >= 0; i--){
            count += nums[i] - maxi;
            if(count < 0) count = 0;
        }
        return count == 0;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isValid(nums, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};