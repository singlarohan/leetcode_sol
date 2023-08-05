class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //using dfs
        // vector<vector<int>> vis(mat.size(), vector<int> (mat[0].size(), 0));
        // auto solve = [&](int i, int j, auto &&self){
        //     if(i >= mat.size() || j >= mat[0].size() || vis[i][j]) return INT_MAX - 1000;
        //     if(mat[i][j] == 0) return 0;
        //     vis[i][j] = 1;
        //     int a = self(i + 1, j, self);
        //     a = min(a, self(i - 1, j, self));
        //     a = min(a, self(i, j + 1, self));
        //     a = min(a, self(i, j - 1, self));
        //     mat[i][j] = 1 + a;
        //     vis[i][j] = 0;
        //     return 1 + a;
        // };
        // for(int i = 0; i < mat.size(); i++)
        //     for(int j = 0; j < mat[0].size(); j++){
        //         if(mat[i][j] == 1)
        //         mat[i][j] = solve(i, j, solve);
        //     }
        // return mat;
        //using bfs
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<vector<int>> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] == 0) {
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();
            int i = temp[0], j = temp[1], steps = temp[2];
            mat[i][j] = steps;
            if(i + 1 < m && !vis[i + 1][j]) {
                q.push({i + 1, j, steps + 1});
                vis[i + 1][j] = 1;
            }
            if(i - 1 >= 0 && !vis[i - 1][j]) {
                q.push({i - 1, j, steps + 1});
                vis[i - 1][j] = 1;
            }
            if(j + 1 < n && !vis[i][j + 1]) {
                q.push({i, j + 1, steps + 1});
                vis[i][j + 1] = 1;
            }
            if(j - 1 >= 0 && !vis[i][j - 1]) {
                q.push({i, j - 1, steps + 1});
                vis[i][j - 1] = 1;
            }
        }
        return mat;
    }
};