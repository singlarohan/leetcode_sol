class Solution {
public:
    int binary_search(vector<int> &nums, int left, int right, int target){
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int left{}, right = nums.size() - 1;
        int pvpt{};
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        pvpt = left;
        cout<<pvpt<<endl;
        //two iterations
        // return max(binary_search(nums, 0, pvpt-1, target), binary_search(nums, pvpt, nums.size() - 1, target));
        //we can do in one iteration by using real mid
        //real mid = (mid + pvpt) % n
        //emzy as fuck motherfuckers
        int n = nums.size();
        left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right)/2;
            int realmid = (mid + pvpt) % n;
            if(nums[realmid] == target) return realmid;
            if(nums[realmid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};