class Solution {
private:
    vector<vector<int>> adj;
    int res = 0;
public:
    int dfs(int node, string &s){
        int n = adj[node].size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto x: adj[node]){
            int temp = dfs(x, s);
            if(s[x] != s[node]) pq.push(temp);
            if(pq.size() > 2) pq.pop();
        }

        int ans = 1;
        vector<int> h;
        while(!pq.empty()){
            h.push_back(pq.top());
            ans += pq.top();
            pq.pop();
        }
        res = max(res, ans);
        //to return
        return h.size() == 2 ? 1 + h[1] : (h.size() == 1 ? 1 + h[0] : 1);
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        adj = vector<vector<int>> (n);
        int root = 0;
        for(int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);
        dfs(0, s);
        return res;
    }
};