class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> mp;
        for(auto x:nums)
            for(auto y:x) mp[y]++;
        
        vector<int> ans;
        
        for(auto it:mp) if(it.second == nums.size()) ans.push_back(it.first);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};