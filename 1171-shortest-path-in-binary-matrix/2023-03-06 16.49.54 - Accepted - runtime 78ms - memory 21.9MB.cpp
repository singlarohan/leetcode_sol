class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> delRow = {-1,-1,-1,0,0,1,1,1};
        vector<int> delCol = {-1,0,1,-1,1,-1,0,1};
        if(grid[0][0] == 1) return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        //using dijkstra's
        queue<pair<int, pair<int, int>>> pq;
        pq.push({1, {0,0}});
        dis[0][0] = 1;
        while(!pq.empty()){
            int dist = pq.front().first;
            int x = pq.front().second.first;
            int y = pq.front().second.second;
            pq.pop();
            for(int k = 0; k < 8; k++){
                int i = delRow[k];
                int j = delCol[k];
                if(x + i >= 0 && x + i < m && y + j >= 0 && y + j < n
                    && grid[x + i][y + j] == 0 && dis[x+i][y+j] > 1 + dist){
                    dis[x+i][y+j] = 1 + dist;
                    pq.push({1 + dist, {x + i, y + j}});
                }
            }
        }
        // USING BFS
        // queue<pair<int, int>> q;
        // q.push({0,0});
        // dis[0][0] = 1;
        // while(!q.empty()){
        //     int x = q.front().first;
        //     int y = q.front().second;
        //     q.pop();
        //     for(int k = 0; k < 8; k++){
        //         int i = delRow[k];
        //         int j = delCol[k];
        //         if(x + i >= 0 && x + i < m && y + j >= 0 && y + j < n
        //           && grid[x + i][y + j] == 0 && dis[x + i][y + j] == INT_MAX){
        //             dis[x + i][y + j] = 1 + dis[x][y];
        //             q.push({x + i, y + j});
        //         }
        //     }
        // }
        return dis[m - 1][n - 1] == INT_MAX ? -1 : dis[m - 1][n - 1];
        
    }
};