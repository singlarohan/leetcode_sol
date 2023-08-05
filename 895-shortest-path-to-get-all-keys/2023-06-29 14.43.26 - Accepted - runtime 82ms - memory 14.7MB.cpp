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

        int ans = INT_MAX;

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
                            //first check if it is a lower alphabet
                            if(tolower(grid[ni][nj]) == grid[ni][nj]){
                                int temp = mask | (1 << (grid[ni][nj] - 'a'));
                                
                                if(temp == (1 << keys) - 1) ans = min(ans, 1 + count);

                                else if(dis[ni][nj][temp] > 1 + count){
                                    dis[ni][nj][temp] = 1 + count;
                                    q.push({temp, {ni, nj}});
                                }
                            }
                            //if not lower then check if it's key is there in the mask
                            //only then can we proceed further
                            else if((mask & (1 << (grid[ni][nj] - 'A'))) != 0){
                                if(dis[ni][nj][mask] > 1 + count){
                                    dis[ni][nj][mask] = 1 + count;
                                    q.push({mask, {ni, nj}});
                                }
                            }
                        }
                        //check if the path is clear
                        //i.e. no obstacle
                        //can only go on if it is not '#'
                        else if(grid[ni][nj] == '.' || grid[ni][nj] == '@') {
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
        return ans == INT_MAX ? -1 : ans;
    }
};