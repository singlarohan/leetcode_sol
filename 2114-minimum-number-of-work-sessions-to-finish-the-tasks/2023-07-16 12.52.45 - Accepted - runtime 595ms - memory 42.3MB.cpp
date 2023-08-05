class Solution {
private:
    vector<vector<int>> dp;
    int n, sTime;
public:
    int solve(int mask, int curr, vector<int> &tasks){
        if(mask == (1 << n) - 1) return curr != 0;

        if(dp[mask][curr] != -1) return dp[mask][curr];        
        
        int ans{INT_MAX};

        for(int i = 0; i < n; i++){
            int temp{INT_MAX};
            if((mask & (1 << i)) == 0){
                if(curr + tasks[i] == sTime)
                    temp = 1 + solve(mask | (1 << i), 0, tasks);
                else if(curr + tasks[i] > sTime) 
                    temp = 1 + solve(mask | (1 << i), tasks[i], tasks);
                else
                    temp = solve(mask | (1 << i), curr + tasks[i], tasks);
            }
            ans = min(ans, temp);
        }
        return dp[mask][curr] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        sTime = sessionTime;
        dp = vector<vector<int>> (1 << n, vector<int> (sessionTime + 1, -1));
        return solve(0, 0, tasks);
    }
};