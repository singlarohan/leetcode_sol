class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[j] - arr[i] == diff){
                    dp[j] = max(dp[j], 1 + dp[i]);
                    ans = max(dp[j], ans);
                }
            }
        }
        return ans;
    }
};