class Solution {
public:
    long long fact(int n, vector<int> &dp){
        if(n == 0 || n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = n * fact(n-1, dp);
    }
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, -1);
        vector<int> ans;
        long long size{1};
        for(int i = 1; i < n; i++){
            if(prices[i] - prices[i - 1] == -1)
                size++;
            else{
                ans.push_back(size);
                size = 1;
            }
        }
        ans.push_back(size);
        long long answ{0};
        for(int i = 0; i <ans.size(); i++){
            answ += fact(ans[i], dp);
        }
        return answ;
    }
};