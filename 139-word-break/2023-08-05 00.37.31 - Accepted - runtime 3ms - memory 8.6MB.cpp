class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        // string temp;
        int n = s.size();
        vector<int> dp(n + 1, -1);
        for(int i = 0; i < wordDict.size(); i++) mp[wordDict[i]] = i;
        auto solve = [&](int i, int prev, auto &&self) -> bool{
            if(i >= n) return true;
            if(dp[i] != - 1) return dp[i];
            string temp;
            bool ans = false;
            for(int j = i; j < n; j++){
                temp += s[j];
                if(mp.find(temp) != mp.end()) {
                    ans |= self(j + 1, prev, self);
                    // cout<<ans<<" "<<temp<<endl;
                    // cout<<i<<endl;
                }
                if(ans) return dp[i] = true;
            }
            return dp[i] = ans;
        };
        return solve(0, 0, solve);
    }
};