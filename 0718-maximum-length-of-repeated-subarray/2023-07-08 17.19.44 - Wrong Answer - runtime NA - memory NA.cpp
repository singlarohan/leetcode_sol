class Solution {
private:
    int n1,n2;
    vector<vector<int>> dp;
public:
    int solve(int i, int j, vector<int> & nums1, vector<int> &nums2){
        if(i >= n1 || j>= n2) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = max(solve(i + 1, j, nums1, nums2), solve(i, j + 1, nums1, nums2));
        ans = max(ans, nums1[i] == nums2[j] ? 1 + solve(i + 1, j + 1, nums1, nums2) : 0);
        
        return dp[i][j] = ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //using dp i will do this once again
        n1 = nums1.size(), n2 = nums2.size();
        dp = vector<vector<int>> (n1, vector<int> (n2, -1));
        return solve(0, 0, nums1, nums2);
    }
};