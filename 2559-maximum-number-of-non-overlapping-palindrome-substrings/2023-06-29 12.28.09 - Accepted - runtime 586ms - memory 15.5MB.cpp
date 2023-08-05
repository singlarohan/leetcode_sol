class Solution {
private:
    vector<vector<bool>>p;
    vector<int> dp;
    int n, k;
public:
    int solve(int i, string &s){
        if(i + k > n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = 0;
        if(k != 1)
        ans = solve(i + 1, s);
        for(int j = i + k - 1; j < n; j++){
            if(p[i][j]){
                ans = max(ans, 1 + solve(j + 1, s));
            }
        }
        return dp[i] = ans;
    }   

    int maxPalindromes(string s, int k1) {
        n = s.size();
        k = k1;
        p = vector<vector<bool>> (n + 1, vector<bool> (n + 1, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i >= j) {
                    p[i][j] = true;
                    continue;
                }
                p[i][j] = (s[i] != s[j] ? false : p[i + 1][j - 1]);
            }
        }
        dp = vector<int> (n, -1);
        return solve(0, s);
    }
};