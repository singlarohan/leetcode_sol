class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int l, int r, char color, string &s){
        if(l == r) return !(s[l] == color);
        if(l > r) return 0;

        if(dp[l][r][color - 'a'] != -1) return dp[l][r][color - 'a'];
        
        if(s[l] == color) return solve(l + 1, r, color, s);
        if(s[r] == color) return solve(l, r - 1, color, s);

        //else four cases
        //change color to front or back
        int ans = 1 + min(solve(l + 1, r, s[l], s), solve(l, r - 1, s[r], s));
        //paint current subsequent indices only and move on
        int new_l = l + 1;
        while(new_l <= r && s[new_l] == s[l]) new_l++;
        ans = min(1 + solve(new_l, r, color, s), ans);

        int new_r = r - 1;
        while(new_r >= l && s[new_r] == s[r]) new_r--;
        ans = min(1 + solve(l, new_r, color, s), ans);

        return dp[l][r][color - 'a'] = ans;
    }
    int strangePrinter(string s) {
        dp = vector<vector<vector<int>>> (s.size(), vector<vector<int>> 
                                                (s.size(),vector<int> (27, -1)));
        return solve(0, s.size() - 1, '{', s);
    }
};