class Solution {
private:
    vector<vector<int>> dp;
    int n;
public:
    int solve(int i, int prev, vector<int> &arr1, vector<int> &arr2){
        if(i >= n) return 0;

        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int last = prev == -1 ? INT_MIN : (prev == 0 ? arr1[i - 1] : arr2[i - 1]);
        
        int ans = solve(i + 1, -1, arr1, arr2);

        if(arr1[i] >= last) ans = max(1 + solve(i + 1, 0, arr1, arr2), ans);
        if(arr2[i] >= last) ans = max(1 + solve(i + 1, 1, arr1, arr2), ans);

        return dp[i][prev + 1] = ans;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp = vector<vector<int>> (n, vector<int> (3, -1));
        
        return solve(0, -1, nums1, nums2);
    }
};