class Solution {
public:
    void solve(int i, vector<vector<int>> &ans, vector<int> &temp, int n, int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(i > n)
            return;
        for(int j = i; j <= n; j++){
            temp.push_back(j);
            solve(j+1, ans, temp, n, k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, ans, temp, n, k);
        return ans;
    }
};