class Solution {
private:
    vector<vector<int>> adj;
    int res = 0;
public:
    int dfs(int node, string &s){
        int temp;
        int maxi1{}, maxi2{};
        //for storing the 2 children with largest possible path
        for(auto x: adj[node]){
            temp = dfs(x, s);
            if(s[x] != s[node]){ 
                if(temp >= maxi1){
                    maxi2 = maxi1;
                    maxi1 = temp;
                }
                else if(temp > maxi2)
                    maxi2 = temp;
            }
        }

        res = max(res, 1 + maxi1 + maxi2);
        //to return
        return 1 + maxi1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        adj = vector<vector<int>> (n);

        for(int i = 1; i < n; i++) 
            adj[parent[i]].push_back(i);

        dfs(0, s);

        return res;
    }
};