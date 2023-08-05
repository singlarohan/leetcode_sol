class Solution {
private:
    vector<int> dp;
public:
    int solve(int i){
        if(dp[i] != -1) return dp[i];
        return solve(i - 1) + solve(i - 2);
    }

    int findIntegers(int n) {
        int m = log2(n) + 1;
        dp = vector<int> (m + 1, -1);
        dp[0] = 1, dp[1] = 2;
        int i = m - 1, pbit = 0, ans = 0;
        while(i >= 0){
            if((n & (1 << i)) != 0){
                ans += solve(i);
                if(pbit == 1){
                    ans--;
                    break;
                }
                pbit = 1;
            }
            else pbit = 0;
            i--;
        }
        return ans + 1;
    }
};