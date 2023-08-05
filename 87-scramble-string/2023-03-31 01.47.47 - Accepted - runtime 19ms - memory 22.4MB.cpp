class Solution {
public:
    vector<vector<vector<int>>> dp;
    string s1, s2;
    bool solve(int i, int j, int n){
        if(n == 1) return s1[i] == s2[j];
        if(dp[i][j][n] != -1) return dp[i][j][n];
        vector<int> mp(26, 0);
        for(int k = 0; k < n; k++){
            mp[s1[i + k] - 'a']++;
            mp[s2[j + k] - 'a']--;
        }
        for(int k = 0; k < 26; k++) if(mp[k] != 0) return dp[i][j][n] = false;
        for(int k = 1; k < n; k++){
            bool a = solve(i + k, j + k, n - k);
            bool b = solve(i, j, k);
            bool c = solve(i, j + k, n - k);
            bool d = solve(i + n - k, j, k);
            if(a && b || c && d) return dp[i][j][n] = true;
        }
        return dp[i][j][n] = false;
    };
    bool isScramble(string s11, string s22) {
        int m = s11.size();
        s1 = s11, s2 = s22;
        dp = vector<vector<vector<int>>> (m, vector<vector<int>> (m, vector<int> (m + 1, -1)));
        return solve(0,0,m);
    }
};