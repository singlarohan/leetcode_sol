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
        // for(int i = 0; i < n; i++){
        //     if(col[i] == -1 && !dfs(i, 0, graph, col)) return false;
        // }
        //using BFS
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(col[i] != -1) continue;
            q.push(i);
            col[i] = 0;
            while(!q.empty()){
                int t = q.front();
                int cur = !col[t];
                q.pop();
                for(auto node:graph[t]){
                    if(col[node] != -1){
                        if(col[node] != cur) return false;
                    }
                    else{
                        col[node] = cur;
                        q.push(node);
                    }
                }
            }
        }
        return true;
    }
};