class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));
        auto solve = [&](int i, int j, auto &&self) -> bool{
            if(i == s.size()){
                while(j < p.size()){
                    if(p[j] != '*')
                        return false;
                    j++;
                }
                return true;
            }
            if(j >= p.size())
                return false;
            if(s[i] == p[j] || p[j] == '?'){
                return dp[i][j] = self(i+1, j+1, self);
            }
            else if(p[j] == '*'){
                for(int k = i; k <= s.size(); k++)
                    if(self(k, j+1, self))
                        return dp[i][j] = true;
            }
            return false;
        };
        return solve(0, 0, solve);
    }
};