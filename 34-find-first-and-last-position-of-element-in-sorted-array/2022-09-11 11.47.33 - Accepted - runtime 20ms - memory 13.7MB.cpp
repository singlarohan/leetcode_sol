class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // O(N)
        // bool flag{false};
        // int start{-1}, end{-1};
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == target){
        //         if(!flag){
        //             start = i;
        //             flag = true;
        //         }
        //         if(flag)
        //             end = i;
        //     }
        // }
        // return {start, end};
        //O(logn)
        int left{}, right = nums.size() - 1;
        int fpos{-1}, lpos{-1};
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                fpos = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                lpos = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return {fpos, lpos};
    }
};