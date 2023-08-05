class Solution {
private:
    vector<vector<int>> dp;
public:
    int maxCoins(vector<int>& nums) {
        dp = vector<vector<int>> (nums.size() + 1, vector<int> (nums.size() + 1, 0));
        for(int i = nums.size() - 2; i >= 0; i--){
            for(int j = 0; j < nums.size(); j++){
                if(i > j) continue;
                int ans{};
                for(int k = i; k <= j; k++){
                    ans = max(ans, (i - 1 >= 0 ? nums[i - 1] : 1) * nums[k] 
                    * (j + 1 < nums.size() ? nums[j + 1] : 1) + dp[i][k]
                    + dp[k + 1][j+1]);
                }
                dp[i][j + 1] = ans;
            }
        }
        // return solve(0, nums.size() - 1, nums);
        return dp[0][nums.size()];
    }
};