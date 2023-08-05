class Solution {
public:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
    
            if (hash1 != hash2) {
                return hash1 ^ hash2;             
            }
            
            // If hash1 == hash2, their XOR is zero.
            return hash1;
        }
    };

    int countPaths(int n, vector<vector<int>>& roads) {
        //Method 1
        // int M = 1e9 + 7;
        // vector<vector<pair<int, int>>> adj(n);
        // for(auto it:roads){
        //     adj[it[0]].push_back({it[1], it[2]});
        //     adj[it[1]].push_back({it[0], it[2]});
        // }
        // priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        // vector<long long> dis(n, 1e14);
        // dis[n - 1] = 0;
        // pq.push({0, n - 1});
        // while(!pq.empty()){
        //     long long curr = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
        //     for(auto it:adj[node]){
        //         if(dis[it.first] > (long long)(it.second) + curr){
        //             dis[it.first] = (long long)(it.second) + curr;
        //             pq.push({dis[it.first], it.first});
        //         }
        //     }
        // }
        // vector<bool> vis(n, false);
        // unordered_map<pair<int, long long>, int, hash_pair> mp;
        // auto dfs = [&](int i, long long cdis, auto &&self){
        //     if(i == n - 1) return 1;
        //     if(mp.find({i,cdis}) != mp.end()) return mp[{i, cdis}];
        //     vis[i] = true;
        //     int ans{};
        //     for(auto it:adj[i]){
        //         if(cdis + it.second + dis[it.first] == dis[0] && !vis[it.first])
        //             ans = (ans + self(it.first, cdis + it.second, self)) % M;
        //     }
        //     vis[i] = false;
        //     return mp[{i, cdis}] = ans % M;
        // };
        // return dfs(0, 0, dfs);
        
        //Method 2 Just dijkstra's
        int M = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;
        vector<long long> dis(n, 1e14);
        vector<int> cnt(n, 0);
        cnt[0] = 1;
        dis[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            long long curr = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dis[it.first] > (long long)(it.second) + curr){
                    dis[it.first] = (long long)(it.second) + curr;
                    cnt[it.first] = cnt[node];
                    pq.push({dis[it.first], it.first});
                }
                else if(dis[it.first] == (long long)(it.second) + curr)
                    cnt[it.first] += cnt[node];
            }
        }
        return cnt[n - 1];

    }
};