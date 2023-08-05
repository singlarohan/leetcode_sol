class Solution {
public:
    // bool solve(int i, vector<int> &nums, int temp1, int temp2, int temp3, int temp4){
    //     if(i >= nums.size()){
    //         if(temp1 == temp2 && temp2 == temp3 && temp3 == temp4)
    //             return true;
    //         return false;
    //     }
    //     return solve(i+1, nums, temp1 + nums[i], temp2, temp3, temp4) || solve(i+1, nums, temp1, temp2 + nums[i], temp3, temp4) || solve(i+1, nums, temp1, temp2, temp3 + nums[i], temp4) || solve(i+1, nums, temp1, temp2, temp3, temp4 + nums[i]);
    // }
    //very bad solution
    bool solve(int i, int sum, int goal, int stick, vector<int> &nums, vector<int> &dp){
        if(sum > goal)
            return false;
        if(sum == goal){
            sum = 0;
            stick--;
            return solve(0, sum, goal, stick, nums, dp);
        }
        if(stick == 1)
            return true;
        if(i >= nums.size())
            return false;
        //choose
        bool ch{false};
        if(dp[i] != 1 && sum + nums[i] <= goal){
            dp[i] = 1;
            ch = solve(i+1, sum + nums[i], goal, stick, nums, dp);
            dp[i] = -1;
        }
        return ch || solve(i+1, sum, goal, stick, nums, dp);
    }
    
    bool makesquare(vector<int>& matchsticks) {
        // return solve(0, matchsticks, 0,0,0,0);
        vector<int> dp(matchsticks.size(), -1);
        int total{}, goal{};
        for(auto &x:matchsticks)
            total += x;
        goal = total/4;
        if(total %4 != 0)
            return false;
        return solve(0, 0, goal, 4, matchsticks, dp);
    }
};