class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr{1};
        for(int i = 1; i < nums.size(); i++){
            while(i < nums.size() && nums[i] == nums[i-1]) i++;
            if(i < nums.size()) nums[curr++] = nums[i];
        }
        return curr;
    }
};