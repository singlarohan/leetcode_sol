class Solution {
private:
    int n;
    vector<int> dp;
public:
    int solve(int i, vector<vector<int>> &env){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        //not take
        int ans = solve(i + 1, env);

        //take
        int j = i + 1;
        while(j < n && (env[i][0] <= env[j][0] || env[i][1] <= env[j][1])) j++;

        ans = max(1 + solve(j, env), ans);

        return dp[i] = ans;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] > b[0];
        });
        n = envelopes.size();

        dp = vector<int> (n, -1);
        
        return solve(0, envelopes);
    }
};