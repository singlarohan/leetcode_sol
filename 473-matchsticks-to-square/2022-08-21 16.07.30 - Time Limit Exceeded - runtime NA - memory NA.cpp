class Solution {
public:
    bool solve(int i, vector<int> &nums, int temp1, int temp2, int temp3, int temp4){
        if(i >= nums.size()){
            if(temp1 == temp2 && temp2 == temp3 && temp3 == temp4)
                return true;
            return false;
        }
        return solve(i+1, nums, temp1 + nums[i], temp2, temp3, temp4) || solve(i+1, nums, temp1, temp2 + nums[i], temp3, temp4) || solve(i+1, nums, temp1, temp2, temp3 + nums[i], temp4) || solve(i+1, nums, temp1, temp2, temp3, temp4 + nums[i]);
    }
    
    bool makesquare(vector<int>& matchsticks) {
        return solve(0, matchsticks, 0,0,0,0);
    }
};