class Solution {
private:
    int n;
    vector<int> delrow{-1,0,0,1};
    vector<int> delcol{0,-1,1,0};
    //manhattan distance per displacement
public:
    int dfs(int i, int j, vector<vector<int>> &grid){
        if(grid[i][j] == 1) return 0;
        
        grid[i][j] = 2;
        int ans = 1e9;
        for(int k = 0; k < 4; k++){
            int ni = i + delrow[k], nj = j + delcol[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] != 2){
                ans = min(ans, 1 + dfs(ni, nj, grid));
            }
        }
        grid[i][j] = 0;
        return ans;
    }

    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = -1e9;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans < -1e8 || ans > 1e8 ? -1 : ans;
    }
};