class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        //dynamic programming
        vector<vector<int>> dp(obstacles.size(), vector<int> (3, -1));
        auto solve = [&](int i, int lane, auto &&self) -> int{
            if(i >= obstacles.size())
                return 0;
            if(obstacles[i] - 1 == lane)
                return INT_MAX - 1000000;
            if(dp[i][lane] != -1)
                return dp[i][lane];
            int a{INT_MAX}, b{INT_MAX}, c{INT_MAX};
            a = self(i + 1, lane, self);
            if(obstacles[i] - 1 != (lane + 1) % 3)
                b = 1 + self(i + 1, (lane + 1) % 3, self);
            if(obstacles[i] - 1 != (lane + 2) % 3)
                c = 1 + self(i + 1, (lane + 2) % 3, self);
            return dp[i][lane] = min(a,min(b,c));
        };
//         for(int i = 0; i < obstacles.size(); i++){
            
//         }
        return solve(0, 1, solve);
    }
};