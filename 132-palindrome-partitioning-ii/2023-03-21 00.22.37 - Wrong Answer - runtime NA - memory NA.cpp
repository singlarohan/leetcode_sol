class Solution {
public:
    int minCut(string s) {
        auto pal = [&](int i, int j, auto &&self){
            if(i >= j) return true;
            if(s[i] != s[j]) return false;
            return self(i + 1, j - 1, self);
        };
        vector<int> dp(s.size(), -1);
        int ans = 1e8;
        auto solve = [&](int i, int j, auto &&self) -> int{
            if(j == s.size()){
                if(pal(i, j-1, pal)) return 0;
                return 1e8;
            }
            if(dp[j] != -1) return dp[j];
            int t = 1e8;
            if(pal(i, j - 1, pal)){
                //inserting new element in temp
                t = 1 + self(j, j + 1, self); 
            }
            //insert at end of last element in temp
            t = min(t, self(i, j + 1, self));
            return dp[j] = t;
        };
        return solve(0, 1, solve);
    }
};