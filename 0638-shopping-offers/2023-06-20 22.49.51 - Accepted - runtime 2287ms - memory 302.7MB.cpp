class Solution {
private:
    int n;
    vector<int> dp;
public:
    int solve(int mask, vector<int> &price, vector<vector<int>>& special){
        if(mask == 0) return 0;
        if(dp[mask] != -1) return dp[mask];
        int ans = 1e9;
        int temp = mask;
        //covering special array
        for(int i = 0; i < special.size(); i++){
            int cost = special[i].back();
            bool flag = true;
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
            if(flag) ans = min(ans, cost + solve(mask, price, special));
            mask = temp;
        }
        for(int i = 0; i < n; i++){
            int cost = price[i];
            int curr = (mask >> (4 * i)) & ((1 << 4) - 1);
            if(curr == 0) continue;
            mask = mask ^ (curr << (4*i));
            mask = mask | ((curr - 1) << (4 * i));
            ans = min(ans, cost + solve(mask, price, special));
            mask = temp;
        }
        return dp[mask] = ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        //4 bits per item
        //total 4 * n bits required
        n = price.size();
        int mask{};
        dp = vector<int> (1 << (4*n), -1);
        for(int i = 0; i < n; i++){
            int a = needs[i] << (4*i);
            mask = mask | a;
        }
        // string binary = bitset<24>(req).to_string();
        // cout<<binary<<endl;
        return solve(mask, price, special);
    }
};