class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it:times)
            adj[it[0]].push_back({it[1], it[2]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(it.second + wt < dis[it.first]){
                    dis[it.first] = it.second + wt;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        int maxi{INT_MIN};
        for(int i = 1; i < n + 1; i++)
            maxi = max(maxi, dis[i]);
        return maxi == INT_MAX ? -1 : maxi;
    }
};