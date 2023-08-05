class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int cnum1 = nums[0], cnum2 = INT_MIN;
        int amini = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > cnum1){
                if(cnum2 != INT_MIN) return true;
                cnum2 = cnum1;
                cnum1 = nums[i];
            }
            else if(nums[i] <= cnum1){
                if(cnum2 == INT_MIN) cnum1 = nums[i];
                else if(cnum2 > nums[i]) cnum1 = nums[i];
                else if(amini = INT_MIN || amini >= nums[i]) amini = nums[i];
                else if(amini < nums[i]){
                    cnum1 = nums[i];
                    cnum2 = amini;
                    amini = INT_MIN;
                }
            }
        }
        return false;
    }
};