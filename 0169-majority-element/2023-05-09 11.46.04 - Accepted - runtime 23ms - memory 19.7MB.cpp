class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = nums[0], n = 1;
        for(int i = 1; i < nums.size(); i++){
            if(x == nums[i]) n++;
            else if(n == 0){
                x = nums[i];
                n = 1;
            }
            else n--;
        }
        return x;
    }
};