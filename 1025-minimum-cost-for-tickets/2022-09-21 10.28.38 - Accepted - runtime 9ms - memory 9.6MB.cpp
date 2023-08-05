class Solution {
public:
    vector<int> dp;
    
    int solve(int i, vector<int> &days, vector<int> &costs){
        if(i >= days.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        // if 1 day pass
        int oday = costs[0] + solve(i + 1, days, costs);
        //if 7 day
        int k = i;
        while(k < days.size() && days[k] - days[i] < 7)
            k++;
        int sday = costs[1] + solve(k, days, costs);
        //if 30 day
        k = i;
        while(k < days.size() && days[k] - days[i] < 30)
            k++;
        int thday = costs[2] + solve(k, days, costs);
        return dp[i] = min(oday, min(sday, thday));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp = vector<int> (days.size(), -1);
        return solve(0, days, costs);
    }
};