class Solution {
public:
    void sortColors(vector<int>& nums) {
        // vector<int> count(3,0);
        // for(int i = 0; i<nums.size(); i++){
        //      count[nums[i]]++;   
        // }
        // for(int i = 0, j = 0; i<nums.size(); i++){
        //     while(count[j] == 0)
        //         j++;
        //     nums[i] = j;
        //     count[j]--;
        // }
        // return;
        
        //ONE PASS
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while(i <= right && left < right){
            if(nums[i] == 0){
                swap(nums[i], nums[left]);
                left++;
            }
            if(nums[i] == 2){
                swap(nums[i], nums[right]);
                right--;
            }
            i++;
        }
    }
};