class Solution {
private:
    int n;
    vector<int> cookies;
    vector<vector<unordered_map<int, int>>> dp;
public:
    int solve(int mask, int target, int num, int curr_sum, vector<int> &coo){
        if(dp[mask][num].count(curr_sum)) return dp[mask][num][curr_sum];
        if(num == 1) {
            for(int i = 0; i < coo.size(); i++){
                if((mask & (1 << i)) == 0){
                    curr_sum += coo[i];
                }
            }
            return dp[mask][num][curr_sum] = curr_sum;
        }

        if(curr_sum >= target){
            int next = ((target * num) - curr_sum)/(num - 1);
            return dp[mask][num][curr_sum] = max(curr_sum, solve(mask,next, num-1, 0, coo));
        }
        
        int ans = INT_MAX;

        for(int i = 0; i < coo.size(); i++){
            if((mask & (1 << i)) == 0){
                ans = min(ans, solve(mask | (1 << i), target, num, curr_sum + coo[i], coo));
            }
        }
        return dp[mask][num][curr_sum] = ans;
    }

    int distributeCookies(vector<int>& coo, int k) {
        n = coo.size();
        dp = vector<vector<unordered_map<int, int>>> (1 << n, vector<unordered_map<int, int>> (k + 1));
        int total = accumulate(coo.begin(), coo.end(), 0);
        return solve(0, total/k, k, 0, coo);
    }
};