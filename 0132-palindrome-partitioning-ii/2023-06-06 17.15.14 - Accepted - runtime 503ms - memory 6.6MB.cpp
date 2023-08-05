class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        
        auto ifpalin = [&](int i, int j, auto &&self){
            if(i >= j) return 1;
            if(s[i] != s[j]) return 0;
            return self(i + 1, j - 1, self);
        };

        auto solve = [&](int i, int j, auto &&self) -> int{
            if(dp[i] != -1) return dp[i];
            if(ifpalin(i, j, ifpalin)) return 0;
            int t = 1e8;
            for(int k = i; k < j; k++){
                if(ifpalin(i, k, ifpalin))
                t = min(t, 1 + self(k+1, j, self));
            }
            return dp[i] = t;
        };
        
        return solve(0, n - 1, solve);
    }
};