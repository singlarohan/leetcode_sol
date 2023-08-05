class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dig_in{1};
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0){
                while(dig_in < i || dig_in < nums.size() && nums[dig_in] == 0)
                    dig_in++;
                if(dig_in < nums.size())
                    swap(nums[i], nums[dig_in]);
                dig_in++;
            }
        }
    }
};