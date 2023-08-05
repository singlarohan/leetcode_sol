class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //using dijkstra's
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});
        vector<double> prob(n,0);
        prob[start] = 1;
        while(!pq.empty()){
            double curr = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // if(node == end) ans = max(curr, ans);
            for(auto it:adj[node]){
                if(curr * it.second > prob[it.first]){
                    prob[it.first] = curr * it.second;
                    pq.push({prob[it.first], it.first});
                }
            }
        }
        return prob[end];
    }
};