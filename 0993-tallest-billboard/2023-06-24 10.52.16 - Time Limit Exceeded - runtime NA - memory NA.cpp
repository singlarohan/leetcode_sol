class Solution {
    vector<unordered_map<int, unordered_map<int, int>>> dp;
    // vector<vector<vector<int>>> dp;
    int sum;
public:
    int solve(int i, int sum1, int sum2, vector<int> &rods){
        int ans{};
        if(sum1 && sum1 == sum2) {
            ans = sum1;
        };
        if(i >= rods.size() || sum1 > sum || sum2 > sum) return ans;
        //not choose

        if(dp[i].find(sum1) != dp[i].end() && dp[i][sum1].find(sum2) != dp[i][sum1].end()) 
            return dp[i][sum1][sum2];
        
        ans = solve(i + 1, sum1, sum2, rods);

        //chose for sum1
        ans = max(ans, solve(i + 1, sum1 + rods[i], sum2, rods));

        //choose for sum2
        ans = max(ans, solve(i + 1, sum1, sum2 + rods[i], rods));

        return dp[i][sum1][sum2] = ans;

    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        sum = accumulate(rods.begin(), rods.end(), 0);
        sum /= 2;
        dp = vector<unordered_map<int, unordered_map<int, int>>> (n);
        return solve(0, 0, 0, rods);
    }
};