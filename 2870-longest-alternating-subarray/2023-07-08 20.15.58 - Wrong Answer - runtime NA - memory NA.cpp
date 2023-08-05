class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int curr = 0;
        int maxi = 0;
        bool flag;
        for(int i = 1; i < nums.size(); i++){
            if(curr == 0){
                if(nums[i] - nums[i - 1] == 1){
                    flag = true;
                    curr = 2;
                }
            }
            else{
                if(flag){
                    if(nums[i] - nums[i - 1] == -1) {
                        curr++;
                        flag = false;
                    }
                    else if(nums[i] - nums[i - 1] == 1){
                        curr = 2;
                        flag = true;
                    }
                    else curr = 0;
                }
                else{
                    if(nums[i] - nums[i - 1] == 1) {
                        curr++;
                        flag = true;
                    }
                    else curr = 0;
                }
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};