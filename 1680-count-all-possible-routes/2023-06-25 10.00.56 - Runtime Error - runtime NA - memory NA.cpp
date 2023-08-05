class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int curr, int fuel, vector<int> &locations, int dest){
        if(fuel < 0) return 0;
        if(fuel == 0) return curr == dest;

        if(dp[curr][fuel] != -1) return dp[curr][fuel];
        int ans = (curr == dest);
        for(int i = 0; i < locations.size(); i++){
            if(i != curr)
            ans += solve(i, fuel - abs(locations[curr] - locations[i]), locations, dest);
        }
        return dp[curr][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp = vector<vector<int>> (locations.size(), vector<int> (fuel + 1, -1));
        return solve(start, fuel, locations, finish);
    }
};