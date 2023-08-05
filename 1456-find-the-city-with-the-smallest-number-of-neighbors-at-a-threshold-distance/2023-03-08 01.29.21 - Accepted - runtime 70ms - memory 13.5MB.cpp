class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        //Using Dijkstra's for all vertices
        pair<int, int> ans = {INT_MIN, INT_MAX};
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++){
            vector<int> dis(n, INT_MAX);
            dis[i] = 0;
            pq.push({0, i});
            while(!pq.empty()){
                int curr = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if(curr >= thresh) {
                    while(!pq.empty()) pq.pop();
                    break;
                }
                for(auto it:adj[node]){
                    if(curr + it.second < dis[it.first]){
                        dis[it.first] = curr + it.second;
                        pq.push({dis[it.first], it.first});
                    }
                }
            }
            int count{};
            for(auto x:dis) if(x <= thresh) count++;
            if(ans.second > count) ans = {i, count};
            else if(ans.second == count && ans.first < i)
                ans.first = i;
        }
        return ans.first;
    }
};