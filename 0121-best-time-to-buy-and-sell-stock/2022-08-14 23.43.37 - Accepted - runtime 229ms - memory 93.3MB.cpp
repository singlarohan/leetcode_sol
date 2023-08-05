class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini{INT_MAX};
        int ans{0};
        for(int i = 0; i<prices.size(); i++){
            mini = min(prices[i], mini);
            ans = max(ans, prices[i] - mini);
        }
        return ans;
    }
};