class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int n, int k, vector<int> &temp){
        if(n < k) return;
        if(k == 0){
            ans.push_back(temp);
            return;
        }

        solve(n - 1, k, temp);

        temp.push_back(n);
        solve(n - 1, k - 1, temp);
        temp.pop_back();

        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(n, k, temp);

        return ans;
    }
};