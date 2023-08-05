class Solution {
private:
    vector<vector<int>> dp;
    int n;
public:
    int maxNonDecreasingLength(vector<int>& arr1, vector<int>& arr2) {
        n = arr1.size();
        dp = vector<vector<int>> (n + 1, vector<int> (3, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int prev = 0; prev <= 2; prev++){
                int last = !prev || !i ? INT_MIN : (prev == 1 ? arr1[i - 1] : arr2[i - 1]);
                
                int ans = 0;
                
                if(prev == 0) ans = dp[i + 1][0];

                if(arr1[i] >= last) ans = max(1 + dp[i + 1][1], ans);
                if(arr2[i] >= last) ans = max(1 + dp[i + 1][2], ans);

                dp[i][prev] = ans;
            }
        }
        return dp[0][0];
    }
};