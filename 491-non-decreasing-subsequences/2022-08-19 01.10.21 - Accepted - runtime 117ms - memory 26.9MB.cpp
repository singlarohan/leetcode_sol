class Solution {
public:
    // unordered_map<vector<int>, bool> mp;
    vector<vector<int>> answ;
    void solve(int i, vector<int> &nums, vector<int> &temp, set<vector<int>> &ans){
        if(i >= nums.size()){
            if(!temp.empty() && temp.size() != 1){
                if(!ans.count(temp)){
                    ans.insert(temp);
                    answ.push_back(temp);
                };
            }
            return;
        }
        if(temp.empty()){
            temp.push_back(nums[i]);
            solve(i + 1, nums, temp, ans);
            temp.pop_back();
            solve(i+1, nums, temp, ans);
        }
        else{
            if(nums[i] >= temp.back()){
                temp.push_back(nums[i]);
                solve(i+1, nums, temp, ans);
                temp.pop_back();
            }
            solve(i+1, nums, temp, ans);
        }
        return;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, temp, ans);
        // for(auto &it: ans)
        //     answ.push_back(it);
        return answ;
    }
};