class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<int> delRow = {1,0,-1,0};
        vector<int> delCol = {0,1,0,-1};
        auto dfs = [&](int i, int j, auto &&self){
            if(i < 0 || i >= m || j < 0 || j >= m || board[i][j] == 'X' || vis[i][j]) return;
            vis[i][j] = true;
            for(int x = 0; x < 4; x++)
                self(i + delRow[x], j + delCol[x], self);
        };
        for(int i = 0; i < m; i++){
            dfs(i, 0, dfs);
            dfs(i, n - 1, dfs);
        }
        for(int j = 0; j < n; j++){
            dfs(0, j, dfs);
            dfs(m - 1, j, dfs);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};