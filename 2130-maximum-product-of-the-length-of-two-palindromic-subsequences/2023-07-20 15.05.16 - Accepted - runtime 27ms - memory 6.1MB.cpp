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
                
                for(int i = n - 1; i >= 0; i--){
                    for(int j = 0; j < n; j++){
                        if(i == n - 1) next[j] = next[j + 1] = 0;

                        if(s[i] == s[j] && (mask & (1 << i)) == 0 && (mask & (1 << j)) == 0) 
                            curr[j + 1] = 1 + next[j];
                        else 
                            curr[j + 1] = max(next[j+1], curr[j]);
                        maxi = max(curr[j + 1], maxi);
                    }
                    next = curr;
                }
                res = max(maxi * l1, res);
            }
        }

        return res;
    }
};