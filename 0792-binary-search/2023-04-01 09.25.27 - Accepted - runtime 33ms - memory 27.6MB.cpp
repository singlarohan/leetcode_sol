class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]) l = mid + 1;
            if(target < nums[mid]) r = mid - 1;
        }
        return -1;
    }
};