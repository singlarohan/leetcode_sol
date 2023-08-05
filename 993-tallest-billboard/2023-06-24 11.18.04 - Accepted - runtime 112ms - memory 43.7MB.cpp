class Solution {
    // unordered_map<int, unordered_map<int, int>> mp;
    vector<vector<int>> dp;
    int sum;
public:
    int solve(int i, int balance, vector<int> &rods){
        if(i >= rods.size()) return balance == sum ? 0: -1e9;

        if(dp[i][balance] != -1) return dp[i][balance];
        
        int ans = 0;
        
        //not choose        
        ans = solve(i + 1, balance, rods);

        //chose for sum1
        ans = max(ans, solve(i + 1, balance - rods[i], rods));

        //choose for sum2
        ans = max(ans, rods[i] + solve(i + 1, balance + rods[i], rods));

        return dp[i][balance] = ans;

    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        sum = accumulate(rods.begin(), rods.end(), 0);
        dp = vector<vector<int>> (n, vector<int> (2*sum + 1, -1));
        return solve(0, sum, rods);
    }
};