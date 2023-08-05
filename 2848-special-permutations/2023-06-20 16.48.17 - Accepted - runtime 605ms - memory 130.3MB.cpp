class Solution {
private:
    vector<vector<int>> dp;
    int M = 1e9 + 7;
    int n;
public:
    int solve (int mask, int prev, vector<int> &nums){
        if(mask == ((1 << n) - 1)) return 1;

        if(dp[mask][prev + 1] != -1) return dp[mask][prev + 1];

        long long ans{};
        for(int k = 0; k < n; k++){
            if((mask & (1 << k)) == 0){
                if(prev == -1 || nums[prev] % nums[k] == 0 || nums[k] % nums[prev] == 0){
                    ans += solve(mask | (1 << k), k, nums);
                    ans %= M;
                } 
            }
        }
        return dp[mask][prev + 1] = ans;
    }

    int specialPerm(vector<int>& nums) {
        n = nums.size();
        dp = vector<vector<int>> (1 << n, vector<int> (n + 1, -1));
        return solve(0, -1, nums);
    }
};