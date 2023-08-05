class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        vector<vector<int>> temp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it:mp)
            temp.push_back({it.second,it.first});
        sort(temp.begin(), temp.end(), greater<>());
        while(k--){
            ans.push_back(temp[k][1]);
        }
        return ans;
    }
};