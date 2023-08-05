class Solution {
public:
    // vector<vector<vector<int>>> dp;
    
//     bool solve(int i, int j, int turn, int score1, int score2, vector<int> nums){
//         if(i > j){
//             if(score1 >= score2)
//                 return true;
//             return false;
//         }
//         if(dp[i][j][turn] != -1)
//             return dp[i][j][turn];
//         if(turn == 0)
//             return dp[i][j][turn] = solve(i + 1, j, 1, score1 + nums[i], score2, nums) || solve(i, j - 1, 1, score1+nums[j], score2, nums);

//         else
//             return dp[i][j][turn] = solve(i + 1, j, 0, score1, score2 + nums[i], nums) && solve(i, j-1, 0, score1, score2 + nums[j], nums);
//     }
    //2nd way just find minimum score possible with optimal choices for Player1
    vector<vector<int>> dp1;
    int solve(int i, int j, vector<int> &nums){
        if(i > j)
            return 0;
        if(dp1[i][j] != -1)
            return dp1[i][j];
        int a = nums[i] + min(solve(i + 1, j - 1, nums), solve(i + 2, j, nums));
        int b = nums[j] + min(solve(i + 1, j - 1, nums), solve(i, j - 2, nums));
        return dp1[i][j] = max(a,b);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        // dp = vector<vector<vector<int>>> (20, vector<vector<int>> (20, vector<int> (2 , -1)));
        // return solve(0, nums.size() - 1, 0, 0, 0, nums);
        dp1 = vector<vector<int>> (nums.size(), vector<int> (nums.size(), -1));
        int pl1 = solve(0, nums.size() - 1, nums);
        int pl2 = accumulate(nums.begin(), nums.end(), 0) - pl1;
        return pl1 >= pl2;
    }
};