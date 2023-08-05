class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int M = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, INT_MAX);
        dis[n] = 0;
        pq.push({0, n});
        while(!pq.empty()){
            int curr = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dis[it.first] > it.second + curr){
                    dis[it.first] = it.second + curr;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        //we don't count when dis[i]  == INT_MAX
        vector<int> dp(n + 1, -1);
        auto dfs = [&](int i, auto &&self){
            if(i == n) 
                return 1;
            if(dp[i] != -1) return dp[i];
            int ans{};
            for(auto it:adj[i])
                if(dis[it.first] < dis[i]) ans = (ans + self(it.first, self));
            return dp[i] = ans % M;
        };
        return dfs(1, dfs);
    }
};