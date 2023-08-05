class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int j, string s, string t){
        if(j >= t.size())
            return 1;
        if(i >= s.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = solve(i+1, j, s, t);
        if(s[i] == t[j])
            ans += solve(i+1, j+1, s, t);
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        vector<int> mp(26, 0);
        for(auto &x:s)
            mp[x - 'a']++;
        for(auto &x:t){
            mp[x - 'a']--;
            if(mp[x - 'a'] < 0)
                return 0;
        }
        dp = vector<vector<int>> (s.size(), vector<int> (t.size(), -1));
        return solve(0, 0, s, t);
    }
};