class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i == s.size() && j == p.size())
                return true;
            if(i >= s.size() || j >= p.size())
                return false;
            if(dp[i][j] != -1)
            return (bool)dp[i][j];
            if(p[j] == s[i]){
                dp[i][j] = self(i+1, j+1, self);
                return (bool)dp[i][j];
            }
                // return dp[i][j] = self(i+1, j+1, self);
            else if(p[j] == '.'){
                p[j] = s[i];
                dp[i][j] = self(i + 1, j + 1, self);
                p[j] = '.';
                return (bool)dp[i][j];
            }
            else if(p[j] == '*'){
                for(int k = i; k <= s.size(); k++){
                    if(k < s.size() && k != i && s[k] != s[k-1])
                        break;
                    if(self(k, j + 1, self)){
                        dp[i][j] = true;
                        return (bool)dp[i][j];
                    }
                    // return dp[i][j] = true;
                }
            }
            dp[i][j] = false;
            return (bool)dp[i][j];
        };
        return solve(0, 0, solve);
    }
};