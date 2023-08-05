class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int, int> dp[nums.size() + 1];
        int ans{1};
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;

                if(dp[j].find(diff) != dp[j].end())
                    cnt = dp[j][diff];
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};