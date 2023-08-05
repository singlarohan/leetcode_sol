class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> ans(2,0);
        int d = min({a,b,c}), f = max({a,b,c}), e = a + b + c - d - f;
        ans[1] = f - d - 2;
        if(d + 1 != e) ans[0]++;
        if(e + 1 != f && d + 2 != e) ans[0]++;
        return ans;
    }
};