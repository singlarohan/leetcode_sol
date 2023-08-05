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
    int findCircleNum(vector<vector<int>>& isCon) {
        //Without Adjacency List
        int n = isCon.size();
        // int ans{};
        // auto dfs = [&](int i, auto &&self){
        //     if(!isCon[i][i]) return false;
        //     isCon[i][i] = 0;
        //     for(int j = 0; j < isCon[i].size(); j++)
        //         if(isCon[i][j]) self(j, self);
        //     return true;
        // };

        // for(int i = 0; i < n; i++)
        //     for(int j = 0; j < n; j++)
        //         if(dfs(j, dfs)) ans++;
        // return ans;
        DSU ds(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isCon[i][j])
                ds.UnionBySize(i, j);
            }
        }
        unordered_set<int> parents;
        for(int i = 0; i < n; i++)
            parents.insert(ds.findUparent(i));
            
        return parents.size();
    }
};