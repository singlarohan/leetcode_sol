class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> mp;
        for(int i = 0; i< score.size(); i++)
            mp[score[i]] = i;
        vector<string> ans(score.size());
        int i = score.size();
        for(auto it: mp){
            if(i == 1)
                ans[it.second] = "Gold Medal";
            else if(i == 2)
                ans[it.second] = "Silver Medal";
            else if(i == 3)
                ans[it.second] = "Bronze Medal";
            else
            ans[it.second] = to_string(i);
            i--;
        }
        return ans;
    }
};