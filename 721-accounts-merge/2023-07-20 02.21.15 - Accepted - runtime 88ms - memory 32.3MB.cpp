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
        unordered_map<string, int> mp;
        //stores string to int translation as well as the parent name
        int n = accounts.size();
        DSU ds(n);

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                else ds.UnionBySize(mp[accounts[i][j]], i);
            }
        } 
        unordered_map<int, vector<string>> ans;
        for(auto it:mp){
            //it.first == current email
            int node = ds.findUPar(it.second);
            if(ans.find(node) == ans.end())
                ans[node].push_back(accounts[it.second][0]);
            
            ans[node].push_back(it.first);
        }
        vector<vector<string>> res;
        for(auto it:ans){
            res.push_back(it.second);
            auto iter = res.back().begin();
            iter++;
            sort(iter, res.back().end());
        }
        return res;
    }
};