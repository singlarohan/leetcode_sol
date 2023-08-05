class Solution {
private:
    vector<vector<int>> dp;
    int n;
public:
    int solve(int i, bool prev, vector<int> &arr1, vector<int> &arr2){
        if(i >= n) return 0;

        if(dp[i][prev] != -1) return dp[i][prev];

        int last = i == 0 ? INT_MIN : (prev ? arr2[i - 1] : arr1[i - 1]);

        int ans = 0;

        if(arr1[i] >= last) ans = max(1 + solve(i + 1, 0, arr1, arr2), ans);
        if(arr2[i] >= last) ans = max(1 + solve(i + 1, 1, arr1, arr2), ans);

        return dp[i][prev] = ans;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp = vector<vector<int>> (n, vector<int> (2, -1));
        
        return solve(0, 0, nums1, nums2);
    }
};