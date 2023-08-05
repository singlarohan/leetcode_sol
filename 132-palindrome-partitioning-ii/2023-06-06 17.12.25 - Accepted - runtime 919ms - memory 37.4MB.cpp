class Solution {
public:
    int minCut(string s) {
        // vector<vector<string>> ans;
        // vector<string> temp;
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        auto ifpalin = [&](int i, int j, auto &&self){
            if(i >= j) return 1;
            if(s[i] != s[j]) return 0;
            return self(i + 1, j - 1, self);
        };
        auto solve = [&](int i, int j, auto &&self) -> int{
            if(j == s.size()){
                if(ifpalin(i, j - 1, ifpalin)) return 0;
                else return 1e8;
                // ans.push_back(temp);
                // return;
            }
            if(dp[i][j] != -1) return dp[i][j];
            int t = 1e8;
            if(ifpalin(i, j - 1, ifpalin)){
                // string a = "";
                // a += s[j];
                // temp.push_back(a);
                t = 1 + self(j, j + 1, self);
                // temp.pop_back();
            }
            // temp.back().push_back(s[j]);
            t = min(t, self(i, j + 1, self));
            // temp.back().pop_back();
            return dp[i][j] = t;
        };
        // string t = "";
        // t += s[0];
        // temp.push_back(t);
        return solve(0, 1, solve);
        // return ans;
    }
};