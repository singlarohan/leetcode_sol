class DSU{
    vector<int> parent;
    vector<int> size;
    // vector<int> rank;

    public:
    DSU(int n){
        parent.resize(n + 1);
        // rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    // void UnionByRank(int u, int v){
    //     int ulp_u = findUPar(u), ulp_v = findUPar(v);
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
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
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
    int dis(vector<int> &p1, vector<int> &p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        DSU ds(n);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                edges.push_back({dis(points[i], points[j]), i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int ans = 0;

        for(auto &x:edges){
            int u = x[1], v = x[2], wt = x[0];
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.UnionBySize(u, v);
                ans += wt;
            }
        }

        return ans;
    }
};