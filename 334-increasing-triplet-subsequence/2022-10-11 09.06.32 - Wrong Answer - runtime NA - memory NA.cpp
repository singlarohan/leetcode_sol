class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> arr(3, INT_MIN);
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > arr[curr]){
                curr++;
                if(curr == 3)
                    return true;
                arr[curr] = nums[i];
            }
            else
                arr[curr] = nums[i];

        }
        return false;
    }
};