class Solution {
public:
    string s1, s2;
    bool solve(int i, int j, int n){
            if(n == 1) return s1[i] == s2[j];
            // if(dp[i][j][n] != -1) return dp[i][j][n];
            for(int k = 1; k < n; k++){
                bool ans = false;
                bool a = solve(i + k, j + k, n - k);
                bool b = solve(i, j, k);
                bool c = solve(i, j + k, n - k);
                bool d = solve(i + n - k, j, k);
                if(a && b || c && d) return true;
                }
            return false;
        };
    bool isScramble(string s11, string s22) {
        int m = s11.size(), n = s22.size();
        s1 = s11, s2 = s22;
        vector<vector<int>> dp;
        
        return solve(0,0,m);
    }
};