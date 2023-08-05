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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int count = 0;
        for(auto x:connections){
            //this means we have an extra cable
            if(ds.findUPar(x[0]) == ds.findUPar(x[1])) count++;
            ds.UnionBySize(x[0], x[1]);
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[ds.findUPar(i)]++;
        }
        priority_queue<int> pq;
        for(auto it:mp) pq.push(it.second);
        pq.pop();
        int req = 0;
        while(!pq.empty()) {
            req += pq.top();
            pq.pop();
        }
        return req > count ? -1 : req;
    }
};