class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int prev2, int prev1, vector<int> &arr){
        if(i >= arr.size())
            return 0;
        int ans{};
        if(dp[1 + prev2][1 + prev1][i] != -1)
            return dp[1 + prev2][1 + prev1][i];
        for(int j = i; j < arr.size(); j++){
            if(prev2 == -1 || arr[j] == arr[prev1] + arr[prev2])
                ans = max(ans, 1 + solve(j + 1, prev1, j, arr));
        }
        return dp[1 + prev2][1 + prev1][i] = ans;
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        dp = vector<vector<vector<int>>> (arr.size() + 1, vector<vector<int>> (arr.size() + 1, vector<int> (arr.size() , -1)));
        int ans{};
        for(int i = 0; i < arr.size(); i++)
            ans = max(ans, 1 + solve(i + 1, -1, i, arr));
        if(ans >= 3)
            return ans;
        return 0;
    }
};