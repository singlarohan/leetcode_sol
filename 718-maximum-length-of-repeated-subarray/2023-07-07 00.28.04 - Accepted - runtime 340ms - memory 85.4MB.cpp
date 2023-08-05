class Solution {
private:
    int n1,n2;
    vector<vector<int>> dp;
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //using dp i will do this once again
        n1 = nums1.size(), n2 = nums2.size();
        dp = vector<vector<int>> (n1 + 1, vector<int> (n2 + 1, 0));
        int ans = 0;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(nums1[i] == nums2[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans;
    }
};