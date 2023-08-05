class Solution {
private:
    int m;
    vector<vector<int>> dp;
    int num;
public:
    int solve(bool ifsmall, int i){
        if(i >= m) return 1;
        if(dp[i][ifsmall] != -1) return dp[i][ifsmall];
        int ans = 0;
        if(ifsmall || (num & (1 << (m - i - 1))) != 0) {
            if((i) < m - 1 && (num & (1 << (m - i - 2))) != 0)
            ans += solve(true, i + 2);
            else ans += solve(ifsmall, i + 2);
        }
        if((num & (1 << (m - i - 1))) != 0) ans += solve(true, i + 1);
        else ans += solve(ifsmall, i + 1);
        return dp[i][ifsmall] = ans;
    }

    int findIntegers(int n) {
        m = log2(n) + 1;
        dp = vector<vector<int>> (m, vector<int> (2, -1));
        num = n;
        int ans = solve(0, 0);
        return ans;
    }
};