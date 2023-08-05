class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit{};
        int mini{INT_MAX},max;
        bool sell{0};
        for(int i = 0; i<prices.size(); i++){
            if(sell){
                if(mini >= prices[i]){
                    mini = prices[i];   
                }
                else{
                    profit += prices[i] - mini;
                    sell = false;
                }
            }
            if(!sell){
                mini = prices[i];
                sell = true;
            }
        }
        return profit;
    }

};