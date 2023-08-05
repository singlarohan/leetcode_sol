class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, 0);
        
        queue<int> q;
        int ans = -1e9;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    //find top k nodes

                    for(auto it:adj[node]){
                        pq.push(vals[it]);
                        if(pq.size() > k) pq.pop();

                        if(!vis[it]){
                            vis[it] = true;
                            q.push(it);
                        }
                    }
                    int curr = vals[node];
                    while(!pq.empty()){
                        if(pq.top() > 0) curr += pq.top();
                        pq.pop();
                    }
                    ans = max(curr, ans);
                }
            }
        }
        return ans;
    }
};