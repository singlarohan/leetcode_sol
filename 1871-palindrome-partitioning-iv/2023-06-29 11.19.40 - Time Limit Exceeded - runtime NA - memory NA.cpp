class Solution {
private:
    int n;
    vector<vector<int>> dp;
public:
    bool check(string &s, int i, int j){
        if(i >= j) return true;
        return (s[i] != s[j] ? false : check(s, i + 1, j - 1));
    }

    bool solve(int i, int k, string &s){
        if(i >= n && k >= 0) return false;
        if(k == 0) return check(s, i, n - 1);
        if(dp[i][k] != -1) return dp[i][k];
        
        bool ans{};

        for(int j = i; j < n; j++){
            if(check(s, i, j))
                ans |= solve(j + 1, k - 1, s);
        }
        return dp[i][k] = ans;
    }

    bool checkPartitioning(string s) {
        n = s.size();
        dp = vector<vector<int>> (n, vector<int> (3, -1));
        // p = vector<vector<int>> (n, vector<int> (n, -1));
        return solve(0, 2, s);
    }
};