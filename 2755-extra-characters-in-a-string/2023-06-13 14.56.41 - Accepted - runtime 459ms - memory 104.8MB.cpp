class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // string curr;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        unordered_set<string> st;

        for(auto x:dictionary) st.insert(x);

        auto solve = [&](int i, int j, auto &&self){
            string curr;
            for(int k = i; k <= j; k++)
                if(k != n) curr += s[k];
            if(j >= n){
                if(st.find(curr) != st.end()) return 0;
                else return j - i;
            }
            if(dp[i][j] != -1) return dp[i][j];

            int ans = self(j + 1, j + 1, self);
            if(st.find(curr) == st.end()) 
                ans += j - i + 1;
            
            ans = min(ans, self(i, j + 1, self));

            return dp[i][j] = ans;
        };
        return solve(0, 0, solve);
    }
};