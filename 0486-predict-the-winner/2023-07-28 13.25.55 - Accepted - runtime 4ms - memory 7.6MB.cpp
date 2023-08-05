class Solution {
public:
    vector<vector<int>> dp;

    int solve(int l, int r, bool turn, vector<int> &nums){
        if(l > r) return 0;
        //turn variable is dependent in l and r so no need to memoise
        if(dp[l][r] != -1) return dp[l][r];

        int ans;

        if(turn)
            //player 1 turn
            ans = max(nums[l] + solve(l + 1, r, !turn, nums), 
                          nums[r] + solve(l, r - 1, !turn, nums));
        
        else ans = min(-nums[l] + solve(l + 1, r, !turn, nums), 
                          -nums[r] + solve(l, r - 1, !turn, nums));
        
        return dp[l][r] = ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        dp = vector<vector<int>> (nums.size(), vector<int> (nums.size(), -1));
        return solve(0, nums.size() - 1, 1, nums) >= 0;
    }
};