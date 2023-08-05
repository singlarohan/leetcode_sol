class Solution {
public:
    //very bad solution
    bool solve(int i, vector<int> &nums, vector<int> &temp, int &goal){
        if(i >= nums.size())
            return (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3]);
        for(int j = 0; j < 4; j++){
            if(temp[j] + nums[i] <= goal){
                temp[j] += nums[i];
                if(solve(i+1, nums, temp, goal))
                    return true;
                temp[j] -= nums[i];
            }
        }      
        return false;
    }
    
    //better
    bool solve2(int i, int sum, int goal, int stick, vector<int> &nums, vector<int> &dp){
        if(sum > goal)
            return false;
        if(sum == goal){
            sum = 0;
            stick--;
            return solve2(0, sum, goal, stick, nums, dp);
        }
        if(stick == 1)
            return true;
        if(i >= nums.size())
            return false;
        //choose
        bool ch{false};
        if(dp[i] != 1 && sum + nums[i] <= goal){
            dp[i] = 1;
            ch = solve2(i+1, sum + nums[i], goal, stick, nums, dp);
            dp[i] = -1;
        }
        return ch || solve2(i+1, sum, goal, stick, nums, dp);
    }
    
    bool makesquare(vector<int>& matchsticks) {

        // vector<int> dp(matchsticks.size(), -1);
        int total{}, goal{};
        for(auto &x:matchsticks)
            total += x;
        goal = total/4;
        if(total %4 != 0)
            return false;
        sort(matchsticks.begin(), matchsticks.end());
        // return solve2(0, 0, goal, 4, matchsticks, dp);
        vector<int> temp(4,0);
        return solve(0, matchsticks, temp, goal);
    }
};