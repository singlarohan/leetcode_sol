class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));
        auto solve = [&](int i, int j, auto &&self) -> bool{
            if(i == s.size() && j == p.size())
                return true;
            if(i >= s.size() || j >= p.size())
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
        if(s.empty()){
            for(int i = 0; i < p.size(); i++)
                if(p[i] != '*')
                    return false;
            return true;
        }
        return solve(0, 0, solve);
    }
};