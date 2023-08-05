class Solution {
private:
    int n;
    vector<int> dp;
public:
    //using front partitioning
    bool ifPal(string &s, int i, int j){
        if(i >= j) return true;
        if(s[i] != s[j]) return false;
        return ifPal(s, i + 1, j - 1);
    }

    int solve(int i, string &s){
        if(ifPal(s, i, n - 1)) return 0;
        
        if(dp[i] != -1) return dp[i];

        int ans{INT_MAX};

        for(int j = i; j < n - 1; j++){
            if(ifPal(s,i,j)){
                ans = min(ans, 1 + solve(j + 1, s));
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        n = s.size();  
        dp = vector<int> (n, -1);
        return solve(0, s);  
    }
};