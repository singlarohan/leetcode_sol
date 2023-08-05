class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        int M = 1e9 + 7;
        vector<int> dp(n + 1, -1);
        auto solve = [&](int i, auto &&self){
            if(i >= n) return 1;
            if(dp[i] != -1) return dp[i];
            if(s[i] == '0') return 0;
            //just going to next
            long long ans{};
            long long curr = s[i] - '0';
            int j{1};
            while(curr <= k && i + j <= n){
                ans = (ans + self(i + j, self)) % M;
                if(i + j >=n) break;
                curr = curr * 10 + s[i + j] - '0';
                j++;
            }
            return dp[i] = ans % M;
        };
        return solve(0, solve);
    }
};