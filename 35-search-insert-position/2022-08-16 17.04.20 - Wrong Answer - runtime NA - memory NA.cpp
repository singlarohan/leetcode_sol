class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            // if(l == r)
            //     return l;
            int mid = (l + r)/2;
            if(l == mid){
                if(nums[r] < target)
                    return r+1;
                else return l+1;
            }

            if(nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};