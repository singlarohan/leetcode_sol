class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //common subsequence in s and rev(s)
        int n = s.size();
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1;
            for (int j = i + 1; j < n; j++){
                if (s[i] == s[j])
                    curr[j] = next[j - 1] + 2;
                else
                    curr[j] = max(next[j], curr[j - 1]);
            }
            next = curr;
        }
        return curr[n - 1];
    }
};