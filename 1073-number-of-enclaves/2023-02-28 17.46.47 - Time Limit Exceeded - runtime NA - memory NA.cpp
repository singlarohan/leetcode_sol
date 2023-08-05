class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<vector<int>> q;
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,-1,0,1};
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1) q.push({i,0});
            if(grid[i][n-1] == 1) q.push({i,n-1});
        }
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 1) q.push({0, j});
            if(grid[m - 1][j] == 1) q.push({m - 1, j});
        }
        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            vis[i][j] = true;
            for(int x = 0; x < 4; x++){
                if(i + delRow[x] >= 0 && i + delRow[x] < m
                && j + delCol[x] >= 0 && j + delCol[x] < n
                && grid[i + delRow[x]][j + delCol[x]] == 1
                && !vis[i + delRow[x]][j + delCol[x]])
                    q.push({i + delRow[x], j + delCol[x]});
            }
        }
        int ans{};
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 1 && !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};