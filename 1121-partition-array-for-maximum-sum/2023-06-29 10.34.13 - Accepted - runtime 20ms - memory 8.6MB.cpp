class Solution {
private:
    vector<int> dp;
public:
    int solve(int i, int k, vector<int> &arr){
        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int maxi = 0;
        int ans{};
        for(int j = i; j < arr.size() && j < i + k; j++){
            maxi = max(maxi, arr[j]);
            ans = max(ans, (j - i + 1) * maxi + solve(j+1, k, arr));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp = vector<int> (arr.size(), -1);
        return solve(0, k , arr);
    }
};