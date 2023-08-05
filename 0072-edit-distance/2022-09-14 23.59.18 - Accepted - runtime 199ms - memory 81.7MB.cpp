class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string word1, string word2){
        if(j >= word2.size())
            return word1.size() - i;
        if(i >= word1.size())
            return word2.size() - j;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(word1[i] != word2[j]){
            //if insert
            int a = solve(i, j + 1, word1, word2);
            //if replace
            int b = solve(i+1, j + 1, word1, word2);
            //if remove
            int c = solve(i+1, j, word1, word2);
            return dp[i][j] = 1 + min(a,min(b,c));
        }
        else
            return dp[i][j] = solve(i + 1, j + 1, word1, word2);
    }
    
    int minDistance(string word1, string word2) {
        dp = vector<vector<int>> (word1.size(), vector<int> (word2.size(), -1));
        return solve(0, 0, word1, word2);
    }
};