class Solution {
public:
    bool dfs(int i, bool cur, vector<vector<int>> & adj, vector<int> &col){
        if(col[i] != -1) return cur == col[i];
        col[i] = cur;
        for(auto node:adj[i]){
            if(!dfs(node, !cur, adj, col)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for(int i = 0; i < n; i++){
            if(col[i] == -1 && !dfs(i, 0, graph, col)) return false;
        }
        return true;
    }
};