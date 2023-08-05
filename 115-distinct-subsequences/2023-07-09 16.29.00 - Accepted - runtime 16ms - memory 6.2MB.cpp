class Solution {
public:
    // int solve(int i, int j, string &s, string &t){
    //     if(j >= t.size())
    //         return 1;
    //     if(i >= s.size())
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = solve(i+1, j, s, t);
    //     if(s[i] == t[j])
    //         ans += solve(i+1, j+1, s, t);
    //     return dp[i][j] = ans;
    // }

    int numDistinct(string s, string t) {
        while(s.size() && t.back() != s.back())
            s.pop_back();
        if(s == t)
            return 1;
        int m = s.size();
        int n = t.size();

        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);
        curr.back() = 1;
        next.back() = 1;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                long long ans = next[j];
                if(s[i] == t[j])
                    ans += next[j+1];
                curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};