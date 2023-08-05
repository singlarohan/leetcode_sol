class Solution {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    bool solve(int i, int j, string &s, string &p){
        if(i >= m && j >= n) return true;
        bool ans = false;
        if(i == m){
            if(j + 1 < n && p[j + 1] =='*')
                ans |= solve(i, j + 2, s, p);
            return dp[i][j] = ans;
        }
        if(j >= n) return false;
        if(dp[i][j] != -1) return dp[i][j];

        if(j + 1 < n && p[j + 1] =='*'){
            ans |= solve(i, j + 2, s, p);
        }
        
        if(s[i] == p[j]){
            ans |= solve(i + 1, j + 1, s, p);
            if(j + 1 < n && p[j + 1] == '*'){
                for(int k = 0; i + k < m && s[i + k] == s[i]; k++)
                    ans |= solve(i + k + 1, j + 2, s, p);
            }
        }
        
        else if(p[j] == '.'){
            if(j + 1 < n && p[j + 1] == '*'){
                for(int k = 1; i + k - 1 < m; k++)
                    ans |= solve(i + k, j + 2, s, p);
            }
            else ans |= solve(i + 1, j + 1, s, p);
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        m = s.size(), n = p.size();
        dp = vector<vector<int>> (m + 1, vector<int> (n + 1, -1));
        return solve(0, 0, s, p);   
    }
};