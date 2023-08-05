class Solution {
    vector<vector<bool>> vis;
    int cap1, cap2, target;
public:
    bool dfs(int i, int j){
        if(i == target || j == target) return true;

        if(i < 0 || j < 0 || i > cap1 || j > cap2) return false;
        
        if(vis[i][j]) return false;

        vis[i][j] = true;

        return dfs(0, j) || dfs(i, 0) || dfs(cap1, j) || dfs(i, cap2)
                || dfs(0, j + i) || dfs(i - (cap2 - j), cap2)
                || dfs(i + j, 0) || dfs(cap1, j - (cap1 - i));
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        cap1 = jug1Capacity, cap2 = jug2Capacity;
        target = targetCapacity;
        vis = vector<vector<bool>> (cap1 + 1, vector<bool> (cap2 + 1, 0));
        return dfs(0, 0);
    }
};