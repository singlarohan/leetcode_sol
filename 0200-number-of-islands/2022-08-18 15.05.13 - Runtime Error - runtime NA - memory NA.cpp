class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans{};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if((!i || grid[i-1][j] == '0') && grid[i][j] == '1'){
                    // if((!i || grid[i-1][j] == '0') && (!j || grid[i][j-1] == '0') && (!(j-grid[0].size() + 1) || grid[i][j+1] == '0') && (!(i - grid.size() + 1) || grid[i+1][j] == '0'))
                    //     ans++;
                    while((j + 1 - grid[0].size()) && grid[i][j+1] == '1' || (i + 1 - grid.size()) && grid[i+1][j] == '1'){
                        if(grid[i][j+1] == '1')
                        j++;
                        else i++;
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};