class Solution {
private:
    int m, n;
    vector<int> r;
    vector<int> c;
public:
    int solve(int i, int j, int count, vector<vector<int>> & grid){
        int ans{};
        for(int k = 0; k < 4; k++){
            int ni = i + r[k], nj = j + c[k];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] != -1){
                if(grid[ni][nj] == 0){
                    grid[ni][nj] = -1;
                    ans += solve(ni, nj, count - 1, grid);
                    grid[ni][nj] = 0;
                    continue;
                }
                else if(grid[ni][nj] == 2)
                    ans += count == 0;
            }
        }
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        r = {-1,0,1,0};
        c = {0,-1,0,1};
        m = grid.size();
        n = grid[0].size();
        int count{}, x{}, y{};
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                count += (grid[i][j] == 0);
                if(grid[i][j] == 1) x = i, y = j;
            }
        cout<<count<<" "<<x<<" "<<y<<endl;
        return solve(x, y, count, grid);
    }
};