class Solution {
private:
    // unordered_set<pair<int, int>, hash_pair> st;
    vector<int> row = {-1,0,0,1};
    vector<int> col = {0,-1,1,0};
public:
    bool checkBFS(int m, int n, vector<vector<bool>> vis){
        queue<pair<int, int>> q;
        
        for(int j = 1; j <= n; j++)
            if(!vis[1][j]) q.push({1, j});
            
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            if(i == m) return true;
            q.pop();
            for(int k = 0; k < 4; k++){
                int ni = i + row[k], nj = j + col[k];
                if(ni >= 1 && ni <= m && nj >= 1 && nj <= n && !vis[ni][nj]){
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        int l = 0, r = cells.size() - 1;

        vector<vector<bool>> vis(m + 1, vector<bool> (n + 1, 0));

        for(int i = 0; i <= ((l + r) / 2); i++) vis[cells[i][0]][cells[i][1]] = 1;
        
        int ans{};

        while(l <= r){
            int mid = (l + r) / 2;

            if(checkBFS(m, n, vis)) {
                l = mid + 1;
                for(int i = mid + 1; i <= ((l + r) / 2); i++) 
                    vis[cells[i][0]][cells[i][1]] = 1;
                ans = max(ans, 1 + mid);
            }
            else{
                r = mid - 1;
                for(int i = mid; i > ((l + r) / 2); i--) 
                    vis[cells[i][0]][cells[i][1]] = 0;
            }
        }
        return ans;
    }
};