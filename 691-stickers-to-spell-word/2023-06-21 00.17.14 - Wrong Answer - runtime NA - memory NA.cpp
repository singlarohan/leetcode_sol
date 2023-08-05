class Solution {
private:
    int m,n;
    unordered_map<char, vector<int>> mp;
    // vector<vector<int>> dp;
    vector<int> dp;
public:
    int solve(int i, int mask, vector<string> &stick){
        if(mask == (1 << (m))  - 1) return 0;
        
        if(i >= n) return 1e9;
        if(dp[mask] != -1) return dp[mask];
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
        return dp[mask] = ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        n = stickers.size();
        m = target.size();
        // dp = vector<vector<int>> (n, vector<int> (1 << m, -1));
        dp = vector<int> (1 << m, -1);
        for(int i = 0; i < m; i++)
            mp[target[i]].push_back(i);
        int ans = solve(0, 0, stickers);
        return ans >= 1e9 ? -1 : ans;
    }
};