class Solution {
private:
    vector<vector<int>> dp;
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3){
        if(i >= s1.size() && j >= s2.size())
            return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(i < s1.size() && s1[i] == s3[i + j])
            ans |= solve(i + 1, j, s1, s2, s3);
        
        if(j < s2.size() && s2[j] == s3[i + j])
            ans |= solve(i, j + 1, s1, s2, s3);
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        // dp = vector<vector<int>> (s1.size() + 1, vector<int> (s2.size() + 1, -1));
        // return solve(0, 0, s1, s2, s3);

        dp = vector<vector<int>> (s1.size() + 2, vector<int> (s2.size() + 2, true));
        int m = s1.size(), n = s2.size();
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                bool ans = false;
                if(i < s1.size() && s1[i] == s3[i + j])
                    ans |= dp[i + 1][j];
                if(j < s2.size() && s2[j] == s3[i + j])
                    ans |= dp[i][j + 1];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};