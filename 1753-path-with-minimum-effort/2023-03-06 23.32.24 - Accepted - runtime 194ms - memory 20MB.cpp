class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hght) {
        int m = hght.size();
        int n = hght[0].size();
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
        dis[0][0] = 0;
        while(!pq.empty()){
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int k = 0; k < 4; k++){
                int i = delRow[k];
                int j = delCol[k];
                if(x + i >= 0 && x + i < m && y + j >= 0 && y + j < n
                && dis[x+i][y+j] > max(dist, abs(hght[x][y] - hght[x+i][y+j]))){
                    dis[x + i][y + j] = max(dist, abs(hght[x][y] - hght[x+i][y+j]));
                    pq.push({dis[x+i][y+j], {x + i, y + j}});
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};