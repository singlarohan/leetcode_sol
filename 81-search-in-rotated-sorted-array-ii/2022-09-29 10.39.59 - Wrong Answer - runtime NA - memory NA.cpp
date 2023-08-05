class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < nums[right])
                right = mid;
            else left = mid + 1;
        }
        int rot = left;
        left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right)/2;
            int realMid = (mid + rot) % n;
            if(nums[realMid] == target) return true;
            else if(nums[realMid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};