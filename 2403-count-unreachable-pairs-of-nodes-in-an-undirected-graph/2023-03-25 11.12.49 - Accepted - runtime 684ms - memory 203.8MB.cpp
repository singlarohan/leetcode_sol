class DSU{
    public:
    vector<long long> parent;
    vector<long long> size;
    // vector<long long> rank;

    DSU(int n){
        parent.resize(n + 1);
        // rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }

    // void UnionByRank(int u, int v){
    //     int ulp_u = findUparent(u), ulp_v = findUparent(v);
    //     if(ulp_u == ulp_v) return;
    //     if(rank[ulp_u] > rank[ulp_v]){
    //         parent[ulp_v] = ulp_u;
    //     }
    //     if(rank[ulp_v] > rank[ulp_u]){
    //         parent[ulp_u] = ulp_v;
    //     }
    //     if(rank[ulp_v] == rank[ulp_u]){
    //         rank[ulp_u]++;
    //         parent[ulp_v] = u;
    //     }
    // }
    void UnionBySize(int u, int v){
        int ulp_u = findUparent(u), ulp_v = findUparent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] >= size[ulp_v]){
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else{
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // DSU ds(n);
        // for(auto it:edges) {
        //     ds.UnionBySize(it[0], it[1]);
        // }
        // vector<long long> count(n , -1);
        // long long ans{};
        // for(int i = 0; i < n; i++)
        //     ans += n - ds.size[ds.findUparent(i)];
        //USING DFS
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        auto dfs = [&](int i, auto &&self) -> int{
            vis[i] = true;
            int count{};
            for(auto it:adj[i]){
                if(!vis[it]){
                    vis[it] = true;
                    count += self(it, self);
                }
            }
            return 1 + count;
        };
        long long ans{};
        for(int j = 0; j < n; j++)
            if(!vis[j]){
                long long posv = dfs(j, dfs);
                ans += posv * (n - posv);
            }
        return ans/2;
    }
};