class Solution {
private:
    int n;
    // vector<int> dp;
    unordered_map<int, int> dp;
    // unordered_map<int, unordered_map<int, int>> dp;
public:
    int solve(int i, int mask, vector<int> &price, vector<vector<int>>& special){
        int ans = 1e9;
        if(dp.find(mask) != dp.end()) return dp[mask];
        if(i >= special.size()){
            ans = 0;
            for(int j = 0; j < n; j++){
                    int curr = (mask >> (4 * j)) & ((1 << 4) - 1);
                    ans += curr * price[j];
            }
        }
        else{
            int temp = mask;
            //covering special array
            int cost = special[i].back();
            bool flag = true;
            //taking ith offer
            for(int j = 0; j < n; j++){
                int curr = (mask >> (4 * j)) & ((1 << 4) - 1);
                if(special[i][j] > curr) {
                    flag = false;
                    break;
                }
                else{
                    mask = mask ^ (curr << (4 * j));
                    curr -= special[i][j];
                    mask = mask | (curr << (4 * j));
                }
            }
            if(flag) ans = cost + solve(i + 1, mask, price, special);
            mask = temp;
            ans = min(ans, solve(i + 1, mask, price, special));
        }
        return dp[mask] = ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        //4 bits per item
        //total 4 * n bits required
        n = price.size();
        int mask{};
        // dp = vector<int> (1 << (4*n), -1);
        for(int i = 0; i < n; i++){
            int a = needs[i] << (4*i);
            mask = mask | a;
        }
        return solve(0, mask, price, special);
    }
};