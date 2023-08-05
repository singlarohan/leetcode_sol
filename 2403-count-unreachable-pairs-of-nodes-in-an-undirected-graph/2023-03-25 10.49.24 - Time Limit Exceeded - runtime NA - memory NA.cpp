class DSU{
    public:
    vector<long long> parent;
    vector<long long> size;
    vector<long long> rank;

    DSU(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }

    void UnionByRank(int u, int v){
        int ulp_u = findUparent(u), ulp_v = findUparent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        if(rank[ulp_v] == rank[ulp_u]){
            rank[ulp_u]++;
            parent[ulp_v] = u;
        }
    }
    void UnionBySize(int u, int v){
        int ulp_u = findUparent(u), ulp_v = findUparent(v);
        if(size[ulp_u] >= size[ulp_v]){
            // size[ulp_u] += size[ulp_v];
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
        DSU ds(n);
        for(auto it:edges) {
            ds.UnionBySize(it[0], it[1]);
            cout<<ds.size[ds.findUparent(it[0])]<<endl;
        }
        vector<long long> count(n , -1);
        long long ans{};
        for(int i = 0; i < n; i++){
            int ulp_i = ds.findUparent(i);
            if(count[ulp_i] == -1){
                count[ulp_i] = 0;
                for(int j = 0; j < n; j++)
                    if(ds.findUparent(j) != ulp_i) count[ulp_i]++;
            }
            ans += count[ulp_i];
        }
        return ans/2;
    }
};