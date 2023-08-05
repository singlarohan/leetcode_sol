class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        // vector<int> ans;
        long long answ{0};
        long long size{1};
        for(int i = 1; i < n; i++){
            if(prices[i] - prices[i - 1] == -1)
                size++;
            else{
                // ans.push_back(size);
                answ += (size*(size+1))/2;
                size = 1;
            }
        }
        answ += (size*(size+1))/2;
        // ans.push_back(size);
        // long long answ{0};
        // for(int i = 0; i <ans.size(); i++){
        //     answ +=((long long)ans[i]*(ans[i]+1))/2;
        // }
        return answ;
    }
};