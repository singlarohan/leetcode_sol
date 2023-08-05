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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int, string> mp;
        unordered_map<string, pair<int, string>> map2;
        //stores string to int translation as well as the parent name

        for(auto x: accounts){
            for(int i = 1; i < x.size(); i++){
                if(map2.find(x[i]) == map2.end()){
                    map2[x[i]] = {mp.size(), x[0]};
                    mp[mp.size()] = x[i];
                }
            }
        }   
        int n = mp.size();
        DSU ds(n);

        for(auto x:accounts){
            for(int i = 2; i < x.size(); i++)
                ds.UnionBySize(map2[x[i]].first, map2[x[1]].first);
        }
        unordered_map<int, vector<string>> ans;
        for(int i = 0; i < n; i++){
            int node = ds.findUPar(i);
            if(ans.find(node) != ans.end()) ans[node].push_back(mp[i]);
            else{
                ans[node].push_back(map2[mp[i]].second);
                ans[node].push_back(mp[i]);
            }
        }
        vector<vector<string>> res;
        for(auto it:ans) res.push_back(it.second);
        for(int i = 0; i < res.size(); i++){
            auto it = res[i].begin();
            it++;
            sort(it, res[i].end());
        }
        return res;
    }
};