class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        auto dfs = [&](int i, int j, auto &&self) -> void{
            if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;
            grid[i][j] = '0';
            self(i - 1, j, self);
            self(i + 1, j, self);
            self(i, j - 1, self);
            self(i, j + 1, self);
        };
        int ans{};
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    cout<<i<<" "<<j<<endl;
                    ans++;
                    dfs(i,j,dfs);
                }
        return ans;
    }
};