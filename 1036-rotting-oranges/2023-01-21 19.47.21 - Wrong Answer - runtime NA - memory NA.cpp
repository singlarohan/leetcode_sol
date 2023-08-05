class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        vector<vector<int>> vis(3, vector<int> (3, 0));
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 2)
                    q.push({i,j,0});
        int time = 0;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int r = temp[0] + delRow[i], c = temp[1] + delCol[i], cnt = temp[2] + 1;
                if(r >= 0 && r < grid.size() && c >= 0 && c < grid.size() && grid[r][c] == 1){
                    q.push({r,c,cnt});
                    grid[r][c] = 2;
                    time = cnt;
                }
            }
            //(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)
        }
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid.size(); j++)
                if(grid[i][j] == 1)
                    return -1;
        return time;
    }
};