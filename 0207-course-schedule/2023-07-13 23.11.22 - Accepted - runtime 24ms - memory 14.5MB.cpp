class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prereq) {
        //cycle detection
        //return false if cycle detected
        //using BFS Kahn's Algorithm
        //topo sort
        //if cycle topo sort return lesser number of
        vector<vector<int>> adj(num);
        for(auto it:prereq)
            adj[it[0]].push_back(it[1]);

        vector<int> indeg(num, 0);
        for(auto x:adj){
            for(auto y:x)
                indeg[y]++;
        }
        queue<int> q;
        for(int i = 0; i < num; i++)
            if(indeg[i] == 0) q.push(i);
        int count{};
        while(!q.empty()){
            int t = q.front();
            q.pop();
            count++;
            for(auto node:adj[t]){
                indeg[node]--;
                if(indeg[node] == 0) q.push(node);
            }
        }
        return count == num;
    }
};