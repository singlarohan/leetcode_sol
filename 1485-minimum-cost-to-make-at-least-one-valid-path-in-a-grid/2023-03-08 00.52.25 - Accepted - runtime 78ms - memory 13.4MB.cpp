class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        vector<int> delRow = {0,0,0,1,-1};
        vector<int> delCol = {0,1,-1,0,0};
        dis[0][0] = 0;
        //1 = right, 2 = left, 3 = down, 4 = up
        while(!pq.empty()){
            int curr = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i = 1; i <= 4; i++){
                int nx = x + delRow[i];
                int ny = y + delCol[i];
                if(nx >= 0 && nx < m && ny >= 0  && ny < n && 
                    dis[nx][ny] > curr + (int)(!(i == grid[x][y]))){
                    dis[nx][ny] = curr + (int)(!(i == grid[x][y]));
                    pq.push({dis[nx][ny], {nx, ny}});
                }
            }
        }
        return dis.back().back();
    }
};