class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0){
                int dig_in{i+1};
                while(dig_in < nums.size() && nums[dig_in] == 0)
                    dig_in++;
                if(dig_in < nums.size())
                    swap(nums[i], nums[dig_in]);
            }
        }
    }
};