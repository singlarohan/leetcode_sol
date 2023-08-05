class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0)
            return {};
        sort(changed.begin(), changed.end());
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto &x:changed){
            if(mp[x] != 0){
                mp[x]--;
                ans.push_back(x/2);
            }
            else
                mp[2*x]++;
        }
        if(ans.size() == changed.size()/2)
            return ans;
        return {};
    }
};