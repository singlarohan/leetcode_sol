class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int cnum1 = nums[0], cnum2 = INT_MIN;
        int amini = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > cnum1){
                if(cnum2 != INT_MIN) return true;
                cnum2 = cnum1;
                cnum1 = nums[i];
            }
            else{
                if(amini < nums[i]){
                    cnum2 = amini;
                    cnum1 = nums[i];
                    amini = INT_MAX;
                }
                else if(cnum2 < nums[i])
                    cnum1 = nums[i];
                else
                    amini = min(amini, nums[i]);
            }
        }
        return false;
    }
};