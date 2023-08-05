class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> prob(n, 0);
        prob[start] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start});
        while(!pq.empty()){
            int node = pq.top().second;
            double currp = pq.top().first;
            if(node == end) return currp;
            pq.pop();
            for(auto &x:adj[node]){
                //x[0] -> next edges
                //x[1] -> it's probability
                if(currp * x.second > prob[x.first]){
                    prob[x.first] = currp * x.second;
                    pq.push({prob[x.first], x.first});
                }
            }
        }
        return prob[end];
    }
};