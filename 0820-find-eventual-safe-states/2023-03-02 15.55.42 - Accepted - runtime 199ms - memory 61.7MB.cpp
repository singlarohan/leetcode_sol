class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // DFS
        // vector<int> vis(n, 0);
        // auto dfs = [&](int i, auto &&self) -> bool{
        //     vis[i] = 2;
        //     for(auto x:graph[i]){
        //         if(vis[x] == 2 || (!vis[x] && self(x, self)))
        //             return true;
        //     }
        //     vis[i] = 1;
        //     return false;
        // };
        // vector<int> ans;
        // for(int i = 0; i < n; i++){
        //     if(!vis[i] && dfs(i, dfs));
        //     if(vis[i] != 2) ans.push_back(i);
        // }
        // return ans;

        //BFS - Topological Sort
        //reverse the edges and then apply topological sort
        vector<vector<int>> adj(graph.size());
        for(int i= 0; i < graph.size(); i++){
            for(auto it:graph[i])
                adj[it].push_back(i);
        }
        vector<int> indeg(adj.size());
        for(int i = 0; i < adj.size(); i++)
            for(auto it:adj[i]) indeg[it]++;
        queue<int> q;
        for(int i = 0; i < adj.size(); i++)
            if(indeg[i] == 0) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it:adj[temp]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};