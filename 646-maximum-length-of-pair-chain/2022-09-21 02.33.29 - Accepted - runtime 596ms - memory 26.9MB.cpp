class Solution {
public:
    int dp[1000][1001];
    
    int solve(int i, int prev, vector<vector<int>> & pairs){
        if(i >= pairs.size())
            return 0;
        int ans{INT_MIN};
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        for(int j = i; j < pairs.size(); j++)
            if(prev == -1 || pairs[j][0] > pairs[prev][1])
                ans = max(ans, solve(j+1, j, pairs));
        
        return dp[i][prev + 1] = 1 + ans;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        sort(pairs.begin(), pairs.end());
        return solve(0, -1, pairs);
    }
};