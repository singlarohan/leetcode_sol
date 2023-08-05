class Solution {
private:
    int j,n; 
    vector<vector<int>> dp;
public:
    int solve(int i, vector<vector<int>> &events, int k){
        if(k == 0 || i == n)
            return 0;

        if(dp[i][k] != -1) return dp[i][k];

        for(j = i + 1; j < n; j++) if(events[i][1] < events[j][0]) break;

        return dp[i][k] = max(events[i][2] + solve(j, events, k - 1), solve(i + 1, events, k));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        dp = vector<vector<int>> (n, vector<int> (k + 1, -1));

        sort(events.begin(), events.end());

        return solve(0, events, k);
    }
};