class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //max level = n + 1
        vector<vector<pair<int, int>>> adj(n);
        for(auto it:flights)
            adj[it[0]].push_back({it[1], it[2]});
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        //cost, level, node
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,src}});
        while(!pq.empty()){
            int dist = pq.top().first;
            int level = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();
            if(level == k + 1) continue;
            for(auto it:adj[node]){
                if(dist + it.second < dis[it.first]){
                    dis[it.first] = dist + it.second;
                    pq.push({dis[it.first], {level + 1, it.first}});
                }
            }
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};