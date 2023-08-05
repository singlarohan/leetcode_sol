class Solution {
public:
    vector<int> findOrder(int numC, vector<vector<int>>& prereq) {
        //we have to return topological sort
        vector<vector<int>> adj(numC);
        for(int i = 0; i < prereq.size(); i++)
            adj[prereq[i][1]].push_back(prereq[i][0]);
        vector<int> indeg(numC);
        for(int i = 0; i < adj.size(); i++)
            for(auto it:adj[i])
                indeg[it]++;
        queue<int> q;
        for(int i = 0; i < numC; i++)
            if(indeg[i] == 0) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it: adj[temp]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        if(numC != ans.size())
        ans.clear();
        return ans;
    }
};