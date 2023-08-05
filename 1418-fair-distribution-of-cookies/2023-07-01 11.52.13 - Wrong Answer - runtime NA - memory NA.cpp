class Solution {
private:
    int n;
    vector<int> cookies;
    vector<vector<int>> dp;
public:
    int solve(int mask, int target, int num, int curr_sum){
        if(mask == (1 << n) - 1) return curr_sum;

        if(dp[mask][num] != -1) return dp[mask][num];

        if(curr_sum >= target){
            if(num == 1) {
                for(int i = 0; i < cookies.size(); i++){
                    if((mask & (1 << i)) == 0){
                        curr_sum += cookies[i];
                    }
                }
                return dp[mask][num] = curr_sum;
            }
            return dp[mask][num] = max(curr_sum, solve(mask,((target * num) - curr_sum)/(num - 1), num-1, 0));
        }
        
        int ans = INT_MAX;

        for(int i = 0; i < cookies.size(); i++){
            if((mask & (1 << i)) == 0){
                ans = min(ans, solve(mask | (1 << i), target, num, curr_sum + cookies[i]));
            }
        }
        return dp[mask][num] = ans;
    }

    int distributeCookies(vector<int>& coo, int k) {
        n = coo.size();
        dp = vector<vector<int>> (1 << n, vector<int> (k + 1, -1));
        int total = accumulate(coo.begin(), coo.end(), 0);
        cookies = coo;
        return solve(0, total/k + total % k, k, 0);
    }
};