class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool flag{false};
        int start{-1}, end{-1};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                if(!flag){
                    start = i;
                    flag = true;
                }
                else
                    end = i;
            }
        }
        return {start, end};
    }
};