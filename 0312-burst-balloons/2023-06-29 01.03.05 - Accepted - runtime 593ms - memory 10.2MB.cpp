class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int i, int j, vector<int> &nums){
        if(i > j)  return 0;
        // if(i == j) return nums[i];

        if(dp[i][j] != -1) return dp[i][j];

        int ans{};
        for(int k = i; k <= j; k++){
            ans = max(ans, (i - 1 >= 0 ? nums[i - 1] : 1) * nums[k] 
            * (j + 1 < nums.size() ? nums[j + 1] : 1) + solve(i, k - 1, nums) + solve(k + 1, j, nums));
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        dp = vector<vector<int>> (nums.size(), vector<int> (nums.size(), -1));
        return solve(0, nums.size() - 1, nums);
    }
};