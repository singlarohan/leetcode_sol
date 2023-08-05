class Solution {
public:
    unordered_map<int, int> num;
    vector<vector<int>> ans;
    vector<int> temp;
    int n;

    void solve(){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(auto &it:num){
            if(it.second == 0) continue;
            num[it.first]--;
            temp.push_back(it.first);
            solve();
            temp.pop_back();
            num[it.first]++;
        }

        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        for(auto x:nums) num[x]++;

        solve();

        return ans;
    }
};