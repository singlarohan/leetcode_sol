class Solution {
public:
    int knightDialer(int n) {
        int M = 1e9 + 7;
        vector<vector<vector<int>>> dp(4,vector<vector<int>> (2, vector<int> (n+1, -1)));
        auto solve = [&](int i, int j, int n, auto &&self) -> long long {
            if(i < 0 || i > 3 || j < 0 || j > 2 || (i == 3 && (j == 0 || 
            j == 2)))  return 0;
            if(n == 0)
                return 1;
            if(j == 2){
                if(dp[i][0][n] != -1)
                    return dp[i][0][n];
            }
            else if(dp[i][j][n] != -1)
                return dp[i][j][n];
            //(i + 2, (j - 1, j + 1)), (i - 2, (j-1, j+1)), 
            long long a = self(i + 2, j - 1, n - 1, self) % M;
            a += self(i + 2, j + 1, n - 1, self) % M;
            a += self(i - 2, j - 1, n - 1, self) % M;
            a += self(i - 2, j + 1, n - 1, self) % M;
            a += self(i + 1, j - 2, n - 1, self) % M;
            a += self(i + 1, j + 2, n - 1, self) % M;
            a += self(i - 1, j - 2, n - 1, self) % M;
            a += self(i - 1, j + 2, n - 1, self) % M;
            if(j == 2) return dp[i][0][n] = a % M;
            else return dp[i][j][n] = a % M;
        };
        long long ans{};
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 2; j++){
                if(j == 0) ans += 2 * solve(i, j, n - 1, solve) % M;
                else ans += solve(i, j, n - 1, solve) % M;
            }
        }
        return ans % M;
    }
};