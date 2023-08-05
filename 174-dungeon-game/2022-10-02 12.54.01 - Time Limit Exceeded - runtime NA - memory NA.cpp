class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        auto solve = [&](int i, int j, int curr, auto &&self){
            if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
                return curr;
            int ans{INT_MIN};
            if(j + 1 < dungeon[0].size())
            ans = max(ans, self(i, j + 1, curr + dungeon[i][j+1], self));
            if(i + 1 < dungeon.size())
            ans = max(ans, self(i+1, j, curr + dungeon[i+1][j], self));
            return min(curr, ans);
        };
        int ans = dungeon[0][0];
        ans = min(ans, solve(0, 0, ans, solve));
        if(ans > 0)
            return 1;
        return 1 + abs(ans);
    }
};