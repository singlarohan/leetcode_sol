class Solution {
private:
    int m,n;
    vector<int> dp;
public:
    int solve(int i, int mask, vector<vector<int>>& students, vector<vector<int>>&mentors){
        if(i >= m) return 0;
        if(dp[mask] != -1) return dp[mask];

        int ans = 0;
        for(int j = 0; j < m; j++){
            if((mask & (1 << j)) != 0) continue;
            int curr = 0;
            for(int k = 0; k < n; k++){
                curr += (students[j][k] == mentors[i][k]);
            }
            ans = max(ans, curr + solve(i + 1, mask | (1 << j), students, mentors));
        }
        return dp[mask] = ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m = students.size();
        n = students[0].size();
        dp = vector<int> (1 << m, -1);
        return solve(0, 0, students, mentors);
    }
};