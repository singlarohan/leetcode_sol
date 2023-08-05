class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            // if(l == r)
            //     return l;
            int mid = (l + r)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};