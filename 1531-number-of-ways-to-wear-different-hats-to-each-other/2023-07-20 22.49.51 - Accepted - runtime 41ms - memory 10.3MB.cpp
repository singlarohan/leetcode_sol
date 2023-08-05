class Solution {
private:
    int M = 1e9 + 7;
    vector<vector<int>> dp;
    int n;
public:
    int solve(int pmask, int hatid, vector<vector<int>> & hats, vector<vector<int>> &persons){
        if(pmask == (1 << n) - 1) return 1;
        if(hatid > 40) return 0;

        if(dp[hatid - 1][pmask] != -1) return dp[hatid - 1][pmask];

        long long ans = solve(pmask, hatid + 1, hats, persons);

        for(auto x:persons[hatid])
            if((pmask & (1 << x)) == 0)
                ans += solve(pmask | (1 << x), hatid + 1, hats, persons);

        return dp[hatid - 1][pmask] = ans % M;
    }
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        vector<vector<int>> persons(41);
        
        for(int i = 0; i < n; i++){
            for(auto x:hats[i])
                persons[x].push_back(i);
        }
        dp = vector<vector<int>> (40, vector<int> (1 << n, -1));

        return solve(0, 1, hats, persons);
    }
};