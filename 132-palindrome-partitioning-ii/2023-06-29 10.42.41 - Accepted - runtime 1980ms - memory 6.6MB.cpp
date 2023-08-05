class Solution {
private:
    int n;
    vector<int> dp;
public:
    //using front partitioning
    bool ifPal(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    int solve(int i, string &s){
        if(i >= n) return -1;

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
        return solve(0, s);  
    }
};