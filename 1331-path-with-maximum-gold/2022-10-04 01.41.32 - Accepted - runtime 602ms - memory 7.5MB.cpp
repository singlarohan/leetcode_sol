class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        auto solve = [&](int i, int j, auto &&self) -> int{
            int up, down, left, right;
            up = down = left = right = 0;
            int temp = grid[i][j];
            grid[i][j] = 0;
            if(i + 1 < grid.size() && grid[i+1][j] != 0)
                down = self(i+1, j, self);
            if(i - 1 >= 0 && grid[i-1][j] != 0)
                up = self(i-1, j, self);
            if(j + 1 < grid[0].size() && grid[i][j+1] != 0)
                right = self(i, j+1, self);
            if(j - 1 >= 0 && grid[i][j-1] != 0)
                left = self(i, j-1, self);
            grid[i][j] = temp;
            return grid[i][j] + max({up, down, left, right});
        };
        int maxi{0};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++)
                maxi = max(maxi, solve(i, j, solve));
        }
        return maxi;
    }
};