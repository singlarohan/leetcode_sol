class Solution {
private:
    int n;
    vector<int> indices;
public:
    bool check_palin(string &s, int mask){
        if(__builtin_popcount(mask) == 1) return true;

        int count = 0;
        for(int i = 0; i < n; i++){
            if(((1 << i) & mask) != 0){
                indices[count++] = i;
            }
        }

        int l = 0, r = count - 1;
        while(l < r)
            if(s[indices[l++]] != s[indices[r--]]) return false;
        
        return true;
    }
    int maxProduct(string s) {
        // FOR EVERY SINGLE PALINDROMIC SUBSEQUENCE FIND THE 
        // LONGEST PALINDROMIC SUBSEQUENCE WITHOUT THOSE INDICES
        n = s.size();
        indices = vector<int> (n);

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        int ans = 0;
        for(int mask = 1; mask < (1 << n); mask++){
            if(check_palin(s, mask)){
                int maxi = 0;

                fill(next.begin(), next.end(), 0);
                
                for(int i = n - 1; i >= 0; i--){
                    for(int j = 0; j < n; j++){
                        if(s[i] == s[j] && (mask & (1 << i)) == 0 && (mask & (1 << j)) == 0) 
                            curr[j + 1] = 1 + next[j];
                        else 
                            curr[j + 1] = max(next[j+1], curr[j]);
                        maxi = max(curr[j + 1], maxi);
                    }
                    next = curr;
                }
                ans = max(maxi * __builtin_popcount(mask), ans);
            }
        }
        return ans;
    }
};