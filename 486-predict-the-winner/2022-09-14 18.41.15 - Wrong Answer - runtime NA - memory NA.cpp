class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    bool solve(int i, int j, int turn, int score1, int score2, vector<int> nums){
        if(i > j){
            if(score1 >= score2)
                return true;
            return false;
        }
        if(dp[i][j][turn] != -1)
            return dp[i][j][turn];
        if(turn == 0)
            return dp[i][j][turn] = solve(i+1, j, 1, score1 + nums[i], score2, nums) || solve(i, j - 1, 1, score1+nums[j], score2, nums);
        else
            return dp[i][j][turn] = solve(i + 1, j, 0, score1, score2 + nums[i], nums) && solve(i, j-1, 0, score1, score2 + nums[j], nums);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        dp = vector<vector<vector<int>>> (20, vector<vector<int>> (20, vector<int> (2 , -1)));
        return solve(0, nums.size() - 1, 0, 0, 0, nums);
    }
};