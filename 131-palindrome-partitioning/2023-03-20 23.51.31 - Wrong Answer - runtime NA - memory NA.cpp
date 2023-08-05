class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        vector<vector<string>> ans;
        vector<string> temp;
        auto ifpalin = [&](int i, int j, auto &&self){
            if(i >= j) return 1;
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] != s[j]) return 0;
            return dp[i][j] = self(i + 1, j - 1, self);
        };
        auto solve = [&](int i, int j, auto &&self){
            if(j == s.size()){
                ans.push_back(temp);
                return;
            }
            if(!temp.empty() && ifpalin(i, j, ifpalin)){
                temp.back().push_back(s[j]);
                self(i, j + 1, self);
                temp.back().pop_back();
            }
            string a = "";
            a += s[j];
            temp.push_back(a);
            self(j, j + 1, self);
            temp.pop_back();
        };
        solve(0, 0, solve);
        return ans;
    }
};