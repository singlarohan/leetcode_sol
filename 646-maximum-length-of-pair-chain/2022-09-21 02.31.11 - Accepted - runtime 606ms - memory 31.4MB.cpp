class Solution {
public:
    int dp[1000][2002];
    
    int solve(int i, int prev, vector<vector<int>> & pairs){
        if(i >= pairs.size())
            return 0;
        int ans{INT_MIN};
        if(dp[i][prev+1001] != -1)
            return dp[i][prev + 1001];
        for(int j = i; j < pairs.size(); j++)
            if(prev == INT_MIN || pairs[j][0] > prev)
                ans = max(ans, solve(j+1, pairs[j][1], pairs));
        
        return dp[i][prev + 1001] = 1 + ans;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp, -1, sizeof(dp));
        sort(pairs.begin(), pairs.end());
        return solve(0, -1001, pairs);
    }
};