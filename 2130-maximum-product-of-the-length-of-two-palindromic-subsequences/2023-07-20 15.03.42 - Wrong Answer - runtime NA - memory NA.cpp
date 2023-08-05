class Solution {
private:
    int n;
public:
    int palSize(string &s, int mask) {
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            if ((mask & (1 << p1)) == 0) p1++;
            
            else if ((mask & (1 << p2)) == 0) p2--;

            else if (s[p1++] != s[p2--]) return 0;
        }
        return __builtin_popcount(mask);
    }

    int maxProduct(string s) {
        n = s.size();
        
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);
        
        int res = 0, l1, maxi;

        for (int mask = (1 << n) - 1; mask > 0; mask--) {
            l1 = palSize(s, mask);
            if (l1 * (s.size() - l1) > res) {
                maxi = 0;

                fill(curr.begin(), curr.end(), 0);

                for (int i = n - 1; i >= 0; i--) {
                    curr[i] = 1;
                    for (int j = i + 1; j < n; j++){
                        if(i == n - 1) next[j] = next[j - 1] = 0;
                        
                        if (s[i] == s[j]  && (mask & (1 << i)) == 0 && (mask & (1 << j)) == 0)
                            curr[j] = next[j - 1] + 2;
                        else
                            curr[j] = max(next[j], curr[j - 1]);
                    }
                    next = curr;
                }
                res = max(curr[n - 1] * l1, res);
            }
        }

        return res;
    }
};