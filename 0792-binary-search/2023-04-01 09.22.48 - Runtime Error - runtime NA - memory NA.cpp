class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]) l = mid + 1;
            if(target < nums[mid]) r = mid - 1;
        }
        return -1;
    }
};