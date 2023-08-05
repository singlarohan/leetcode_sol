class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp (n1+2, vector<int> (n2+2));
        dp[n1][n2] = 1;

        for(int i = n1; i >= 0; i--){
            for(int j = n2; j >= 0; j--){
                if(i == n1 && j == n2) continue;

                if(s1[i] == s3[i + j]){
                    int ans1 = dp[i+1][j];
                    dp[i][j] = ans1;
                    if(ans1) continue;
                }
                if(s2[j] == s3[i + j]){
                    int ans2 = dp[i][j+1];
                    dp[i][j] = ans2;
                    if(ans2) continue;
                }
                dp[i][j] = 0;
            }
        }  
        return dp[0][0];
    }
};