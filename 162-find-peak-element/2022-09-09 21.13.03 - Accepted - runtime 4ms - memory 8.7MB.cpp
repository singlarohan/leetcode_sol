class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l{INT_MIN}, r;
        for(int i = 0; i< nums.size(); i++){
            if(i == nums.size() - 1)
                r = INT_MIN;
            else
                r = nums[i + 1];
            if(nums[i] >= l && nums[i] >= r)
                return i;
            l = nums[i];
        }
        return -1;
    }
};