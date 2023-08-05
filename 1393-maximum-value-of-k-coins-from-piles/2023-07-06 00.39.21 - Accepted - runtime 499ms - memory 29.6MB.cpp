class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int i, vector<vector<int>> &piles, int k){
        if(i >= piles.size() || k == 0) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int ans = solve(i + 1, piles, k);
        
        int curr{};
        for(int j = 0; j < piles[i].size() && j < k; j++){
            curr += piles[i][j];
            ans = max(curr + solve(i + 1, piles, k - j - 1), ans);
        }
        
        return dp[i][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp = vector<vector<int>> (piles.size(), vector<int> (k + 1, -1));
        return solve(0, piles, k);
    }
};