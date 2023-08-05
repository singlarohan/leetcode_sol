class Solution {
private:
    int n;
public:
    bool palSize(string &s, int mask) {
        int p1 = 0, p2 = s.size();
        while (p1 < p2) {
            if ((mask & (1 << p1)) == 0) p1++;
            
            else if ((mask & (1 << p2)) == 0) p2--;

            else if (s[p1++] != s[p2--]) return false;
        }
        return true;
    }

    int maxProduct(string s) {
        // FOR EVERY SINGLE PALINDROMIC SUBSEQUENCE FIND THE 
        // LONGEST PALINDROMIC SUBSEQUENCE WITHOUT THOSE INDICES
        n = s.size();
        int mask = (1 << n) - 1;

        vector<bool> dp(mask + 1);

        for(int mask = 0; mask < (1 << n); mask++)
            dp[mask] = palSize(s, mask);
        
        int res = 0;

        for (int m1 = mask; m1; m1--) {
            if (dp[m1] * (__builtin_popcount(m1)) * 
                        (s.size() - __builtin_popcount(m1) * dp[m1]) > res) {
                for(int m2 = mask ^ m1; m2; m2 = (m2 - 1) & (mask ^ m1)) {
                    res = max(res, __builtin_popcount(m1) * 
                                    __builtin_popcount(m2) * dp[m1] * dp[m2]);
                }
            }
        }

        return res;
    }
};