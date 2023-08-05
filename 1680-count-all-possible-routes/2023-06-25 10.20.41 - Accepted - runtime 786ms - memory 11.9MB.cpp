class Solution {
private:
    vector<vector<int>> dp;
    int M = 1e9 + 7;
public:
    int solve(int curr, int fuel, vector<int> &locations, int dest){
        // if(fuel == 0) return curr == dest;

        if(dp[curr][fuel] != -1) return dp[curr][fuel];
        long long ans = (curr == dest);
        for(int i = 0; i < locations.size(); i++){
            if(i != curr && fuel - abs(locations[curr] - locations[i]) >= 0)
            ans += solve(i, fuel - abs(locations[curr] - locations[i]), locations, dest);
        }
        return dp[curr][fuel] = ans % M;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // dp = vector<vector<int>> (locations.size(), vector<int> (fuel + 1, -1));
        // return solve(start, fuel, locations, finish);
        
        dp = vector<vector<int>> (locations.size() + 1, vector<int> (fuel + 2, 0));
        int n = locations.size();

        for(int f = 0; f <= fuel; f++){
            for(int curr = 0; curr < n; curr++){
                long long ans = (curr == finish);
                for(int i = 0; i < locations.size(); i++){
                    if(i != curr && f - abs(locations[curr] - locations[i]) >= 0)
                    ans += dp[i][f - abs(locations[curr] - locations[i])];
                }
                dp[curr][f] = ans % M;
            }
        }
        return dp[start][fuel];
    }
};