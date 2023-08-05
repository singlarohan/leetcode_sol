class Solution {
public:
    vector<int> dp;
    
    int solve(int i, string s){
        if(i >= s.size())
            return 1;
        if(s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int choose1 = 0;
        int choose2 = 0;
        if(i < s.size() - 1){
            if(s[i] < '2' || (s[i] == '2' && s[i + 1] <= '6'))
                 choose2 = solve(i + 2, s);
        }
        choose1 = solve(i + 1, s);
        return dp[i] = choose1 + choose2;
    }
    
    int numDecodings(string s) {
        dp = vector<int> (s.size(), -1);
        return solve(0, s);
    }
};