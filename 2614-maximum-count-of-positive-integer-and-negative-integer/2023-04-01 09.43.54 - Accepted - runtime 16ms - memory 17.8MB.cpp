class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //left most zero
        //and right most zero
        int lz{-1}, rz = 1e9;
        int l = 0, r = nums.size() - 1;
        while(l <= r && nums[l] < 0){
            int mid = (l + r)/2;
            if(nums[mid] >= 0)
                r = mid - 1;
                // if(nums[mid] == -1) lz = mid;
            else {
                l = mid + 1;
                lz = mid;
            }
        }
        l = 0, r = nums.size() - 1;
        while(l <= r && nums[r] > 0){
            int mid = (l + r)/2;
            if(nums[mid] <= 0)
                l = mid + 1;
                // if(nums[mid] == 1) rz = mid;
            else {
                r = mid - 1;
                rz = mid;
            }
        }
        return max(lz + 1, (int)nums.size() - rz);
    }
};