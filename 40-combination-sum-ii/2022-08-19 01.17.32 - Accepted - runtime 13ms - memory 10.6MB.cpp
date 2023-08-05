class Solution {
public:

    void solve(int i, int target, vector<vector<int>> &ans, vector<int> &temp, vector<int> & cand){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || i >= cand.size())
            return;
        for(int j = i; j < cand.size(); j++){
            if(j > i && cand[j-1] == cand[j] ){
                continue;
            }
            temp.push_back(cand[j]);
            solve(j+1, target - cand[j], ans, temp, cand);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, target, ans, temp, candidates);
        return ans;
    }
};