class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxCol(grid[0].size(), -1);
        vector<int> maxRow(grid.size(), -1);
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++){
                maxCol[j] = max(maxCol[j], grid[i][j]);
                maxRow[i] = max(maxRow[i], grid[i][j]);
            }
        int ans{};
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                ans += min(maxCol[j], maxRow[i]) - grid[i][j];
        return ans;
    }
};