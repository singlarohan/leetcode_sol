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
        // dp = vector<int> (s.size() + 1, 1);

        int curr{}, next1 = 1, next2 = 1;

        for(int i = s.size() - 1; i >= 0; i--){
            int ans{};
            if(s[i] != '0') 
                ans += next1;
            if(s[i] != '0' && i + 1 < s.size() && (s[i] - '0') * 10 + s[i + 1] - '0' < 27) 
                ans += next2;
            next2 = next1;
            curr = ans;
            next1 = curr;
        }
        return curr;

    }
};