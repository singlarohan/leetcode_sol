class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int j, vector<int> &num1, vector<int> &num2){
        if(i >= num1.size() || j >= num2.size())
            return 0;
        int a = 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(num1[i] != num2[j])
            return 0;
        return dp[i][j] = 1 + solve(i + 1, j + 1, num1, num2);
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp = vector<vector<int>> (nums1.size(), vector<int> (nums2.size(), -1));
        int ans{};
        for(int i = 0; i < nums1.size(); i++)
            for(int j = 0; j < nums2.size(); j++)
                ans = max(ans, solve(i, j, nums1, nums2));
        return ans;
    }
};