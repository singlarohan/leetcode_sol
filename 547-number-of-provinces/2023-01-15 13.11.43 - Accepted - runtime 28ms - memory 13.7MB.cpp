class Solution {
public:
    int findCircleNum(vector<vector<int>>& isCon) {
        //Without Adjacency List
        int n = isCon.size();
        int ans{};
        auto dfs = [&](int i, auto &&self){
            if(!isCon[i][i]) return false;
            isCon[i][i] = 0;
            for(int j = 0; j < isCon[i].size(); j++)
                if(isCon[i][j]) self(j, self);
            return true;
        };

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dfs(j, dfs)) ans++;
        return ans;
    }
};