class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r - 1){
            // if(l == r)
            //     return l;
            int mid = (l + r)/2;
            if(nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        if(nums[l] >= target)
            return l;
        if(nums[r] < target)
            return r+1;
        else return l+1;
    }
};