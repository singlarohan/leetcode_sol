class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] >= i + 1)
                return i + 1;
        }
        return -1;
    }
};