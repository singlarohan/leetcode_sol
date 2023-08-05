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
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0,src}});
        while(!q.empty()){
            int dist = q.front().first;
            int level = q.front().second.first;
            int node = q.front().second.second;
            q.pop();
            if(level >= k + 1) continue;
            for(auto it:adj[node]){
                if(dist + it.second < dis[it.first]){
                    dis[it.first] = dist + it.second;
                    q.push({dis[it.first], {level + 1, it.first}});
                }
            }
        }
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};