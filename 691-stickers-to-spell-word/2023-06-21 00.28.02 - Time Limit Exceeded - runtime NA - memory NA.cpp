class Solution {
private:
    int m,n;
    unordered_map<char, vector<int>> mp;
    vector<vector<int>> dp;
public:
    int solve(int i, int mask, vector<string> &stick){
        if(mask == (1 << (m))  - 1) return 0;
        
        if(i >= n) return 1e9;
        if(dp[i][mask] != -1) return dp[i][mask];
        int temp = mask;
        int ans = 1e9;
        //if take
        for(auto x:stick[i]){
            if(mp.find(x) == mp.end()) continue;
            vector<int> idx = mp[x];
            for(auto y:idx){
                if((mask & (1 << y)) == 0){
                    mask = mask | (1 << y);
                    break;
                }
            }
        }
        if(mask != temp)
        ans = min(ans, 1 + solve(i, mask, stick));
        // if not take
        mask = temp;
        ans = min(ans, solve(i + 1, mask, stick));
        // if(ans >= 1e9) return -1;
        return dp[i][mask] = ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        n = stickers.size();
        m = target.size();
        // dp = vector<vector<int>> (n, vector<int> (1 << m, -1));
        for(int i = 0; i < m; i++)
            mp[target[i]].push_back(i);

        //TABULATION
        dp = vector<vector<int>> (n + 1, vector<int> (1 << m, 1e9));
        int c = 1 << m;
        for(int i = 0; i <= n; i++)
            dp[i][c - 1] = 0;

        for(int i = n - 1; i >= 0; i--){
            for(int mask = c - 2; mask >= 0; mask--){
                int temp = mask;
                int ans = 1e9;
                for(auto x:stickers[i]){
                    if(mp.find(x) == mp.end()) continue;
                    vector<int> idx = mp[x];
                    for(auto y:idx){
                        if((mask & (1 << y)) == 0){
                            mask = mask | (1 << y);
                            break;
                        }
                    }
                }
                if(mask != temp)
                ans = min(ans, 1 + dp[i][mask]);
                // if not take
                mask = temp;
                ans = min(ans, dp[i+1][mask]);
                dp[i][mask] = ans;
            }
        }
        int ans = dp[0][0];
        // int ans = solve(0, 0, stickers);
        return ans >= 1e9 ? -1 : ans;
    }
};