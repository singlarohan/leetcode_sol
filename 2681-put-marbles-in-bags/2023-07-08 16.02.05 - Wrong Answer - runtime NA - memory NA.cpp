class Solution {
private:
    int n;
    vector<vector<pair<long long, long long>>> dp;
    //maxi, mini
public:
    pair<long long, long long> solve(int i, int k, vector<int> &arr){
        if(n - i < k) return {-1e9, 1e9};

        if(k == 1) return {arr[i] + arr[n - 1], arr[i] + arr[n - 1]};

        if(dp[i][k].first != -1) return dp[i][k];

        pair<long long, long long> ans = {-1e9, 1e9};
        for(int j = i; j < n - k + 1; j++){
            auto curr = solve(i + 1, k - 1, arr);
            ans.first = max(ans.first, arr[i] + arr[j] + curr.first);
            ans.second = min(ans.second, arr[i] + arr[j] + curr.second);
        }
        return dp[i][k] = ans;
    }

    long long putMarbles(vector<int>& weights, int k) {
        n = weights.size();
        dp = vector<vector<pair<long long, long long>>> (n, 
                                        vector<pair<long long, long long>> (k + 1, {-1, -1}));
        auto ans = solve(0, k, weights);

        return ans.first - ans.second;

    }
};