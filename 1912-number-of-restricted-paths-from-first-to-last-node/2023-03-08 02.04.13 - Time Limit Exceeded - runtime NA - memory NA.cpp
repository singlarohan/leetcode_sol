class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dis(n + 1);
        dis[n - 1] = 0;
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 1; i < n; i++){
            vector<int> temp(n + 1, INT_MAX);
            pq.push({0, i});
            temp[i] = 0;
            while(!pq.empty()){
                int curr = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    if(temp[it.first] > it.second + curr){
                        temp[it.first] = it.second + curr;
                        pq.push({temp[it.first], it.first});
                    }
                }
            }
            dis[i] = temp[n];
        }
        int count{};
        //we don't count when dis[i]  == INT_MAX
        auto dfs = [&](int i, auto &&self){
            if(i == n) {
                count++;
                return;
            }
            for(auto it:adj[i])
                if(dis[it.first] < dis[i]) self(it.first, self);
            return;
        };
        dfs(1, dfs);
        return count;
    }
};