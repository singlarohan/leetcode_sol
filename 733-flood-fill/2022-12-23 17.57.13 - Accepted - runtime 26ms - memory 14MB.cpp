class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x = image[sr][sc];
        if(color == x) return image;
        auto solve = [&](int i, int j, auto &&self) -> void{
            if(i < 0 || j < 0 || i >= image.size() || 
               j >= image[0].size() || image[i][j] != x) return;
            image[i][j] = color;
            self(i + 1, j, self);
            self(i, j + 1, self);
            self(i - 1, j, self);
            self(i, j - 1, self);
            return;
        };
        solve(sr,sc,solve);
        return image;
    }
};