class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int mod = 1e9 + 7;
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(m, 
                    vector<vector<int>> (n, vector<int> (k + 1, -1)));
        vector<vector<int>> cumsum(m  + 1, vector<int> (n + 1, 0));
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                cumsum[i][j] = cumsum[i+1][j] + cumsum[i][j+1] - cumsum[i+1][j+1];
                cumsum[i][j] += pizza[i][j] == 'A' ? 1 : 0;
                // base case++
                if(cumsum[i][j] > 0) dp[i][j][k - 1] = 1;
            }
        }
        // auto solve = [&](int i, int j, int count, auto &&self){        
        //     if(count ==  k - 1) return 1;
        //     if(dp[i][j][count] != -1) return dp[i][j][count];
        //     //check if no further apples :'(
        //     if(cumsum[i][j] == 0) return 0;
        //     int ans{};
        //     // horizontal cuts
        //     for(int k = i + 1; k < m; k++){
        //         // check if cut valid ;)
        //         if(cumsum[i][j]-cumsum[k][j]){
        //             ans +=self(k, j, count + 1, self);
        //             ans %= M;
        //         }
        //     }
        //     // vertical cuts
        //     for(int k = j + 1; k < n; k++){
        //         // check if cut valid :D
        //         if(cumsum[i][j]-cumsum[i][k]){
        //             ans += self(i, k, count + 1, self);
        //             ans %= M;
        //         }
        //     }
        //     return dp[i][j][count] = ans;
        // };
    auto topDown = [&](int x, int y, int k, const int& n, const int& m, int& K, auto &&self){
        if(k==K-1) return 1;
        if(dp[x][y][k]>-1) return dp[x][y][k];
        // check for 0 apples in submatrix
        if(cumsum[x][y]==0) return 0;
        
        int ret = 0;
        // horizontal cuts
        for(int i=x+1; i<n; i++){
            // check if cut valid
            if(cumsum[x][y]-cumsum[i][y]){
                ret +=self(i, y, k+1, n, m, k, self);
                ret %= mod;
            }
        }
        
        // vertical cuts
        for(int j=y+1; j<m; j++){
            // check if cut valid
            if(cumsum[x][y]-cumsum[x][j]){
                ret +=self(x, j, k+1, n, m, k, self);
                ret %= mod;
            }
        }
        dp[x][y][k] = ret;
        return ret;
    };
        // return solve(0, 0, 0, solve);
        return topDown(0, 0, 0, m, n, k, topDown);
    }
};