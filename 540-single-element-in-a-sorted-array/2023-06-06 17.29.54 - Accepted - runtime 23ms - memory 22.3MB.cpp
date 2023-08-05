class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right)/2;
            // cout<<left<<" "<<right<<" "<<mid<<" "<<nums[mid]<<endl;
            if(mid + 1 < n && nums[mid] == nums[mid + 1]){
                if((mid + 1) % 2 == 0) right = mid - 1;
                else left = mid + 2;
            } 
            else if(mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
                if((mid) % 2 ==  0) right = mid - 1;
                else left = mid + 1;
            }
            else
                return nums[mid];
        }
        return nums[right];
    }
};