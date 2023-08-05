class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n + 1, 1);
        vector<int> ways(n + 1, 1);
        
        int maxi = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < 1 + dp[j]){
                        ways[i] = 0;
                        dp[i] = 1 + dp[j];
                    }

                    if(dp[i] == 1 + dp[j]) ways[i] += ways[j];

                    maxi = max(dp[i], maxi);
                }
            }
        }
        int ans{};
        
        for(int i = 0; i < n; i++)
            if(dp[i] == maxi) ans += ways[i];
        
        return ans;
    }
};