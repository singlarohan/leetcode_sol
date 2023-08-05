class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, count{1};
        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1] != nums[i]){
                nums[k] = nums[i];
                k++;
                count = 1;
            }
            else if(count < 2){
                nums[k] = nums[i];
                count++;
                k++;
            }
        }
    return k;
    }
};