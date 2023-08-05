class Solution {
public:
    void solve(int i, int target, vector<int>& cand, vector<int> &curr, vector<vector<int>> &ans){

        if(target < 0)
            return;
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(i >= cand.size())
            return;
        curr.push_back(cand[i]);
        solve(i , target - cand[i], cand, curr, ans);
        curr.pop_back();
        solve(i+1, target, cand, curr, ans);
            
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(0, target, candidates, curr, ans);
        return ans;
    }
};