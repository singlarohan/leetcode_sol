class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        for(auto it:restricted) vis[it] = true;

        queue<int> q;
        int count = 1;
        vis[0] = true;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    count++;
                    q.push(it);
                }
            }
        }
        return count;
    }
};