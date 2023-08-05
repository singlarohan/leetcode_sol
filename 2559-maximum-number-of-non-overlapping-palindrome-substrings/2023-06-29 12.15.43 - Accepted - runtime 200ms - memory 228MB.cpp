class Solution {
private:
    vector<vector<int>>p;
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
        p = vector<vector<int>> (n, vector<int> (n, 0));
        for (int len = 1; len <= k + 1; ++len)
            for (int i = 0, j = i + len - 1; j < s.size(); ++i, ++j)
                p[i][j] = (len < 3 ? true : p[i + 1][j - 1]) && (s[i] == s[j]);   
        dp = vector<int> (n, -1);
        return solve(0, s);
    }
};