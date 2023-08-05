class Solution {
public:

    vector<vector<vector<int>>> dp;
    int solve(int count, int i, vector<int> &rating, int prev){
        if(count == 0)
            return 1;
        if(i >= rating.size())
            return 0;
        if(dp[i][prev + 2][count - 1] != -1)
            return dp[i][prev + 2][count-1];
        int ans{};
        for(int j = i; j < rating.size(); j++){
            if(prev == -1 || rating[j] > rating[prev])
                ans += solve(count - 1, j + 1, rating, j);
        }
        return dp[i][prev + 2][count-1] = ans;
    }
    
    int numTeams(vector<int>& rating) {
        dp = vector<vector<vector<int>>> (rating.size(), vector<vector<int>> (rating.size() + 2, vector<int> (3, -1)));
        int ans1 = solve(3, 0, rating, -1);
        dp = vector<vector<vector<int>>> (rating.size(), vector<vector<int>> (rating.size() + 2, vector<int> (3, -1)));
        reverse(rating.begin(), rating.end());
        int ans2 = solve(3, 0, rating, -1);
        return ans1 + ans2;
    }
};