class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hght) {
        int m = hght.size();
        int n = hght[0].size();
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        dis[0][0] = 0;
        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            for(int k = 0; k < 4; k++){
                int i = delRow[k];
                int j = delCol[k];
                if(x + i >= 0 && x + i < m && y + j >= 0 && y + j < n
                && dis[x+i][y+j] > abs(hght[x][y] - hght[x+i][y+j])){
                    dis[x + i][y + j] = abs(hght[x][y] - hght[x+i][y+j]);
                    pq.push({x + i, y + j});
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};