class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int, int> dp;
        
        int ans = 0;
        
        for(int i = n - 1; i >= 0; i--){
            int next = arr[i] + diff;

            int clen = 1;
            if(dp.find(next) != dp.end()) clen += dp[next];

            dp[arr[i]] = clen;
            
            ans = max(ans, clen);
        }
        return ans;
    }
};