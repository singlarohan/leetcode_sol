class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int keys = 0;
        int startx{}, starty{};

        queue<pair<int, pair<int, int>>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isalpha(grid[i][j])) keys++;
                else if(grid[i][j] == '@') 
                    startx = i, starty = j;
            }
        }
        keys /= 2;
        vector<vector<vector<int>>> dis(m, vector<vector<int>> 
                                                (n, vector<int> (1 << keys, INT_MAX)));
        //(grid[i][j] - 'a')th bit is needed

        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,-1,0,1};

        q.push({0, {startx, starty}});
        dis[startx][starty][0] = 0;
        int count{};

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int mask = q.front().first;
                int i = q.front().second.first;
                int j = q.front().second.second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                        if(isalpha(grid[ni][nj])){
                            if(tolower(grid[ni][nj]) == grid[ni][nj]){
                                int temp = mask | (1 << (grid[ni][nj] - 'a'));
                                if(dis[ni][nj][temp] > 1 + count){
                                    dis[ni][nj][temp] = 1 + count;
                                    q.push({temp, {ni, nj}});
                                }
                            }

                            else if((mask & (1 << (grid[ni][nj] - 'A'))) != 0){
                                if(dis[ni][nj][mask] > 1 + count){
                                    dis[ni][nj][mask] = 1 + count;
                                    q.push({mask, {ni, nj}});
                                }
                            }
                        }
                        else if(grid[ni][nj] == '.' || grid[i][j] == '@') {
                            if(dis[ni][nj][mask] > 1 + count){
                                dis[ni][nj][mask] = 1 + count;
                                q.push({mask, {ni, nj}});
                            }
                        }
                    }
                }
            }
            count++;
        }
        int mini = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mini = min(mini, dis[i][j][(1 << keys) - 1]);
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};