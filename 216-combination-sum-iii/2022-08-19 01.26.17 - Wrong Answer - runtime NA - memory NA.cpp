class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, int k, int n, vector<int> temp){
        if(k < 0 || n < 0)
            return;
        if(!n && !k){
            ans.push_back(temp);
            return;
        }
        if(8 - i + temp.size() < k || i > 9)
            return;
        //if choose
        temp.push_back(i);
        solve(i+1, k-1, n-i, temp);
        temp.pop_back();
        // not choosing
        solve(i+1, k, n, temp);
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        solve(1, k, n, temp);
        return ans;
    }
};