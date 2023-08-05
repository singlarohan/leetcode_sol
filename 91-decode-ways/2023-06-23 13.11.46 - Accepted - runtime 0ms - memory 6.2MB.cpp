class Solution {
private:
    vector<int> dp;
public:
    int solve(int i, string &s){
        if(i >= s.size()) return 1;
        if(dp[i] != -1) return dp[i];

        int ans{};
        //take 1
        if(s[i] != '0') ans += solve(i + 1, s);
        //take 2
        if(s[i] != '0' && i + 1 < s.size() && (s[i] - '0') * 10 + s[i + 1] - '0' < 27) 
            ans += solve(i + 2, s);

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        // dp = vector<int> (s.size(), -1);
        // return solve(0, s);

        //TABULATION
        dp = vector<int> (s.size() + 1, 1);

        for(int i = s.size() - 1; i >= 0; i--){
            int ans{};
            if(s[i] != '0') 
                ans += dp[i + 1];
            if(s[i] != '0' && i + 1 < s.size() && (s[i] - '0') * 10 + s[i + 1] - '0' < 27) 
                ans += dp[i + 2];
            dp[i] = ans;
        }
        return dp[0];

    }
};