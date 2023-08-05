class Solution {
private:
    int m;
    vector<vector<int>> dp;
    vector<bool> num;
public:
    int solve(bool ifsmall, int i){
        if(i >= m) return 1;
        if(dp[i][ifsmall] != -1) return dp[i][ifsmall];
        int ans = 0;
        if(ifsmall || num[i] == 1) {
            if((i + 1) < m && num[i + 1] == 1)
            ans += solve(true, i + 2);
            else ans += solve(ifsmall, i + 2);
        }
        if(num[i] == 1) ans += solve(true, i + 1);
        else ans += solve(ifsmall, i + 1);
        return dp[i][ifsmall] = ans;
    }

    int findIntegers(int n) {
        m = log2(n) + 1;
        dp = vector<vector<int>> (m, vector<int> (2, -1));
        for(int i = 0; i < m; i++)
            num.push_back(((1 << (m - i - 1)) & n) != 0);
        for(auto x:num)
        cout<<x;
        cout<<endl;
        int ans = solve(0, 0);
        return ans;
    }
};