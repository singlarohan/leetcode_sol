class Solution {
private:
    int n,target;
    vector<int> dp;
public:
    int solve(int i, vector<int> &nums){
        if(i == n - 1) return 0;
        
        if(dp[i] != -1) return dp[i];

        int ans = -1e9;
        
        for(int j = i + 1; j < n; j++){
            if((abs)(nums[j] - nums[i]) <= target){
                ans = max(1 + solve(j, nums), ans);
            }
        }
        return dp[i] = ans;
    }
    
    int maximumJumps(vector<int>& nums, int targ) {
        target = targ;
        n = nums.size();
        
        dp = vector<int> (n, -1);
        
        int ans = solve(0, nums);
        
        return ans <= -1e8 ? -1 : ans;
    }
};