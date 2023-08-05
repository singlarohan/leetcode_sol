class Solution {
private:
    vector<vector<bool>>p;
    vector<vector<bool>> pvis;
    vector<int> dp;
    int n, k;
public:
    bool check(int i, int j, string &s){
        if(i >= j) return true;
        if(pvis[i][j] != 0) return p[i][j];
        pvis[i][j] = 1;
        return p[i][j] = (s[i] != s[j] ? false : check(i + 1, j - 1, s));
    }

    int solve(int i, string &s){
        if(i + k > n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = 0;
        if(k != 1)
        ans = solve(i + 1, s);
        for(int j = i + k - 1; j < n; j++){
            if(check(i, j, s)){
                ans = max(ans, 1 + solve(j + 1, s));
            }
        }
        return dp[i] = ans;
    }   

    int maxPalindromes(string s, int k1) {
        n = s.size();
        k = k1;
        p = vector<vector<bool>> (n, vector<bool> (n, 0));
        pvis = vector<vector<bool>> (n, vector<bool> (n, 0));
        dp = vector<int> (n, -1);
        return solve(0, s);
    }
};