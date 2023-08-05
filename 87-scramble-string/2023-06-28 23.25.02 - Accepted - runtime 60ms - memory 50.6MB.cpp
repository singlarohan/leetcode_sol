class Solution {
public:
    vector<vector<vector<int>>> dp;
    string s1, s2;
    vector<int> mp;
    bool solve(int i, int j, int n){
        if(n == 1) return s1[i] == s2[j];
        if(dp[i][j][n] != -1) return dp[i][j][n];
        for(int k = 0; k < n; k++){
            mp[s1[i + k] - 'a']++;
            mp[s2[j + k] - 'a']--;
        }
        bool flag{};
        for(int k = 0; k < 26; k++) {
            if(mp[k] != 0) {
                flag = true;
                mp[k] = 0;
            }
        }
        if(flag) return dp[i][j][n] = false;
        for(int k = 1; k < n; k++){
            if(solve(i + k, j + k, n - k) && solve(i, j, k) 
            || solve(i, j + k, n - k) && solve(i + n - k, j, k)) 
                return dp[i][j][n] = true;
        }
        return dp[i][j][n] = false;
    };
    bool isScramble(string s11, string s22) {
        int m = s11.size();
        s1 = s11, s2 = s22;
        dp = vector<vector<vector<int>>> (2*m, vector<vector<int>> (2*m, vector<int> (2*m + 1, -1)));
        mp = vector<int> (26, 0);
        return solve(0,0,m);
    }
};