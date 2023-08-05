class Solution {
private:
    vector<vector<int>> dp, p;
    int n;
public:
    int count(int i, int j, string &s){
        if(i >= j) return 0;
        if(p[i][j] != -1) return p[i][j];

        return p[i][j] = (int)(s[i] != s[j]) + count(i + 1, j - 1, s);
        //if a string is palindrome it will be 0
    }

    int solve(int i, int k, string &s){
        if(i >= n) return 1e8;
        if(k == 0) return count(i, n - 1, s);
        
        if(dp[i][k] != -1) return dp[i][k];

        int ans = 1e8;
        for(int j = i; j < n; j++){
            ans = min(ans, count(i, j, s) + solve(j + 1, k - 1, s));
            // if(i == 0 || i == 1) cout<<i<<" "<<j<<" "<<k<<" "<<count(i, j, s)<<endl;
        }
        return dp[i][k] = ans;
    }

    int palindromePartition(string s, int k) {
        n = s.size();
        p = vector<vector<int>> (n, vector<int> (n , -1));
        dp = vector<vector<int>> (n, vector<int> (k, -1));
        return solve(0, k - 1, s);
    }
};