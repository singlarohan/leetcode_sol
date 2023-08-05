class Solution {
private:
    int M = 1e9 + 7;
    vector<vector<int>> dp;
    int n;
public:
    int solve(int pmask, int hatid, vector<vector<int>> & hats, vector<long long> &hmask){
        if(pmask == (1 << n) - 1) return 1;
        if(hatid > 40) return 0;

        if(dp[hatid - 1][pmask] != -1) return dp[hatid - 1][pmask];

        long long ans = solve(pmask, hatid + 1, hats, hmask);

        for(int i = 0; i < n; i++){
            if((pmask & (1 << i)) == 0 && (hmask[i] & (1LL << hatid)) != 0){
                ans += solve(pmask | (1 << i), hatid + 1, hats, hmask);
            }
        }

        return dp[hatid - 1][pmask] = ans % M;
    }
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        vector<long long> hmask(n);
        
        dp = vector<vector<int>> (40, vector<int> (1 << n, -1));

        for(int i = 0; i < n; i++){
            long long temp = 0;
            for(auto x:hats[i]) temp |= (1 << x);
            hmask[i] = temp;
        }
        
        return solve(0, 1, hats, hmask);
    }
};