class Solution {
public:
    int findCircleNum(vector<vector<int>>& isCon) {
        vector<vector<int>> adj(isCon.size());
        for(int i = 0; i < isCon.size(); i++)
            for(int j = 0; j < isCon[i].size(); j++)
                if(isCon[i][j]) adj[i].push_back(j);
        auto dfs = [&](int i, auto &&self) -> void{
            isCon[i][i] = false;
            for(auto &x:adj[i])
                if(isCon[x][x]) self(x, self);
            return;
        };
        int ans{};
        for(int i = 0; i < isCon.size(); i++){
            if(isCon[i][i]){
                dfs(i, dfs); 
                ans++;
            }
        }
        return ans;
    }
};