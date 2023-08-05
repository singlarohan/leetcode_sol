class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //using dfs
        vector<vector<int>> vis(mat.size(), vector<int> (mat[0].size(), 0));
        auto solve = [&](int i, int j, auto &&self){
            if(i >= mat.size() || j >= mat[0].size() || vis[i][j]) return INT_MAX - 1000;
            if(mat[i][j] == 0) return 0;
            vis[i][j] = 1;
            int a = self(i + 1, j, self);
            a = min(a, self(i - 1, j, self));
            a = min(a, self(i, j + 1, self));
            a = min(a, self(i, j - 1, self));
            vis[i][j] = 0;
            return 1 + a;
        };
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat.size(); j++){
                mat[i][j] = solve(i, j, solve);
            }
        return mat;
    }
};