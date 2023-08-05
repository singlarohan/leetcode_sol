class Solution {
public:
    int findCircleNum(vector<vector<int>>& isCon) {
        vector<vector<int>> adj(isCon.size());
        for(int i = 0; i < isCon.size(); i++)
            for(int j = 0; j < isCon[i].size(); j++)
                if(isCon[i][j]) adj[i].push_back(j);
        vector<int> vis(isCon.size());
        auto dfs = [&](int i, auto &&self) -> void{
            vis[i] = true;
            for(auto &x:adj[i])
                if(!vis[x]) self(x, self);
            return;
        };
        int ans{};
        for(int i = 0; i < isCon.size(); i++){
            if(!vis[i]){
                dfs(i, dfs); 
                ans++;
            }
        }
        return ans;
    }
};