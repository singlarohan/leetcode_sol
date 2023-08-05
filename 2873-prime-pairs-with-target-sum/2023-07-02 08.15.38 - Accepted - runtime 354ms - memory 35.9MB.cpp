class Solution {
private:
    vector<vector<int>> ans;
public:
    void sieve(int n)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        for (int p = 2; p <= n/2; p++){
            if (prime[p] && prime[n - p]){
                ans.push_back({p, n - p});
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        sieve(n);
        return ans;
    }
};