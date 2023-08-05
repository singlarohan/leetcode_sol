class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<array<int, 2>> q;
        
        int fresh = 0;
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                fresh += grid[i][j] == 1;
            }

        int time = 0;

        array<int, 4> delRow = {-1, 0, 1, 0};
        array<int, 4> delCol = {0, +1, 0, -1};
        
        int cnt = 1, size;
        int r, c;
        array<int, 2> temp;

        while(!q.empty()){
            size = q.size();
            while(size--){
                temp = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    r = temp[0] + delRow[i], c = temp[1] + delCol[i];

                    if(r >= 0 && r < grid.size() && c >= 0 
                        && c < grid[0].size() && grid[r][c] == 1){
                        
                        q.push({r,c});
                        grid[r][c] = 2;
                        time = cnt;
                        fresh--;
                    }
                }
            }
            cnt++;
            //(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)
        }
        if(fresh > 0) return -1;
        return time;
    }
};