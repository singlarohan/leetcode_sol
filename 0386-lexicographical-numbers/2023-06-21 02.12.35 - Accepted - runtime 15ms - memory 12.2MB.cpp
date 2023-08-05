class Solution {
private:
    vector<int> ans;
public:
    void dfs(int i, int n){
        if(i > n) return ;
        ans.push_back(i);
        for(int j = 0; j <= 9; j++)
            dfs(10*i + j, n);
        return;
    }

    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++)
            dfs(i, n);
        return ans;
    }
};