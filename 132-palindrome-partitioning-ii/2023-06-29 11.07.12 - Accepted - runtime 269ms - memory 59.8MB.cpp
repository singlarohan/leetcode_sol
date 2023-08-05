class Solution {
private:
    int n;
    vector<int> dp;
    vector<vector<int>> p;
public:
    //using front partitioning
    bool ifPal(string &s, int i, int j){
        if(i >= j) return true;
        if(p[i][j] != -1) return p[i][j];
        return p[i][j] = (s[i] != s[j] ? false : ifPal(s, i + 1, j - 1));
    }

    int solve(int i, string &s){
        if(i >= n) return -1;

        if(ifPal(s, i, n - 1)) return 0;

        if(dp[i] != -1) return dp[i];

        int ans{INT_MAX};

        for(int j = i; j < n; j++){
            if(ifPal(s,i,j)){
                ans = min(ans, 1 + solve(j + 1, s));
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        n = s.size();  
        dp = vector<int> (n, -1);
        p = vector<vector<int>> (n, vector<int> (n, -1));
        return solve(0, s);  
    }
};