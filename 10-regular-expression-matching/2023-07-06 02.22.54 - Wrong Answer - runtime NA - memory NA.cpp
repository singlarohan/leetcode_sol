class Solution {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    bool solve(int i, int j, string &s, string &p){
        if(i == m && j == n) return true;
        if(i == m) return p[j] == '*';
        if(j == n) return false;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j]) return solve(i + 1, j + 1, s, p);

        int ans = false;

        if(p[j] == '*'){
            for(int k = 0; i + k - 1 < m && s[i + k - 1] == s[i - 1]; k++)
                ans |= solve(i + k, j + 1, s, p);
        }
        else if(p[j] == '.'){
            if(j + 1 < m && s[j + 1] == '*'){
                for(int k = 0; i + k - 1 < m; k++)
                    ans |= solve(i + k, j + 2, s, p);
            }
            else ans |= solve(i + 1, j + 1, s, p);
        }
        return dp[i][j] = true;
    }
    bool isMatch(string s, string p) {
        m = s.size(), n = p.size();
        dp = vector<vector<int>> (m, vector<int> (n, -1));
        return solve(0, 0, s, p);   
    }
};