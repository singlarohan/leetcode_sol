class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> delRow = {-1,-1,-1,0,0,1,1,1};
        vector<int> delCol = {-1,0,1,-1,1,-1,0,1};
        if(grid[0][0] == 1) return -1;
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0,0}});
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        dis[0][0] = 1;
        while(!pq.empty()){
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(auto i:delRow)
                for(auto j:delCol)
                    if(x + i >= 0 && x + i < m && y + j >= 0 && y + j < n
                      && grid[x + i][y + j] == 0 && dis[x+i][y+j] > 1 + dist){
                        dis[x+i][y+j] = 1 + dist;
                        pq.push({1 + dist, {x + i, y + j}});
                    }
        }
        return dis[m - 1][n - 1] == INT_MAX ? -1 : dis[m - 1][n - 1];
    }
};