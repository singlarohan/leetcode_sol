class Solution {
private:
    unordered_map<string, int> mp;
    unordered_map<int, string> rmp;
    vector<vector<int>> adj;
    unordered_map<int, unordered_map<int, int>> vis;
public:
    string dfs(int node, int count){
        string fun = "";
        for(auto x:adj[node]){
            if(vis[node][x] != 0){
                vis[node][x]--;

                string temp = rmp[x] + dfs(x, count - 1);
                if(temp.size() / 3 == count && (fun.empty() || temp < fun))
                    fun = temp;

                vis[node][x]++;
            }
        }
        return fun;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        mp["JFK"] = 0;
        rmp[0] = "JFK";
        int count = 1;
        for(auto &x:tickets){
            if(!mp.count(x[0])) {
                mp[x[0]] = count;
                rmp[count++] = x[0];
            }
            if(!mp.count(x[1])) {
                mp[x[1]] = count;
                rmp[count++] = x[1];
            }
            while(adj.size() < count) adj.push_back({});
            
            vis[mp[x[0]]][mp[x[1]]]++;

            adj[mp[x[0]]].push_back(mp[x[1]]);
        }
        string temp = dfs(0, tickets.size());
        
        vector<string> ans;
        ans.push_back("JFK");
        for(int i = 0; i < temp.size(); i += 3)
            ans.push_back(temp.substr(i, 3));
        return ans;
    }
};