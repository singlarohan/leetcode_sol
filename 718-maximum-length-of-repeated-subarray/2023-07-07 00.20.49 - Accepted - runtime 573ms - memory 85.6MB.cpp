class Solution {
private:
    int n1,n2;
    vector<vector<int>> dp;
public:
    int solve(int i, int j, vector<int> & nums1, vector<int> &nums2){
        if(i >= n1 || j >= n2 || nums1[i] != nums2[j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = 1 + solve(i + 1, j + 1, nums1, nums2);
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //using dp i will do this once again
        n1 = nums1.size(), n2 = nums2.size();
        dp = vector<vector<int>> (n1, vector<int> (n2, -1));
        int ans = 0;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                ans = max(ans, solve(i, j, nums1, nums2));
            }
        }
        return ans;
    }
};