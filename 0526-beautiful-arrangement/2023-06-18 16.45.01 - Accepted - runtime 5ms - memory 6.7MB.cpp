class Solution {
public:
    int countArrangement(int n) {
        //2^n- 1
        int req = pow(2, n) - 1;
        vector<int> dp(req + 1, -1);
        int num = 0;
        auto solve = [&](int ind, auto &&self){
            if(ind == n + 1) return 1;
            if(dp[num] != -1) 
                return dp[num];

            int ans{};
            for(int i = 0; i < n; i++){
                if((num & (1 << i)) == 0){
                    int cn = i + 1;
                    if(ind % cn == 0 || cn % ind == 0){
                        num = num | 1 << i;
                        ans += self(ind + 1, self);
                        num = num ^ 1 << i;
                    }
                }
            }
            return dp[num] = ans;
        };
        return solve(1, solve);
    }
};