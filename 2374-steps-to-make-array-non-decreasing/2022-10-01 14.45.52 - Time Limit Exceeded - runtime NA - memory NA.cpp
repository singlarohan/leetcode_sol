class Solution {
public:
    int totalSteps(vector<int>& nums) {
        bool flag{false};
        int count{0};
        while(1){
            int prev_val{-1};
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == INT_MAX)
                    continue;
                int temp = nums[i];
                if(prev_val != -1 && prev_val > nums[i]) nums[i] = INT_MAX, flag = true;
                prev_val = temp;
            }
            if(flag) count++, flag = false;
            else break;
        }
        return count;
    }
};