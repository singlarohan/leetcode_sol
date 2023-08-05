class Solution {
private:
    vector<vector<int>> ans;
public:
    void solve(int i, int target, vector<int> & cand, vector<int> &curr){
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(i >= cand.size()) return;
        //take current
        if(target - cand[i] >= 0){
            curr.push_back(cand[i]);
            solve(i, target - cand[i], cand, curr);
            curr.pop_back();
        }
        //not take
        solve(i + 1, target, cand, curr);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(0, target, candidates, curr);
        return ans;
    }
};