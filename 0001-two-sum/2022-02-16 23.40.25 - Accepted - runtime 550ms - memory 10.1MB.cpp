class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        bool flag{};
        for(i = 0; i<nums.size()-1; i++){
            for(j = i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                flag = 1;
                break;
                }
            }
        if(flag)
        break;
        }
        return {i,j};
    }
};