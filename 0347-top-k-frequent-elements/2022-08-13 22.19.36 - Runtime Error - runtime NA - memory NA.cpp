class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans, temp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it:mp)
            temp.push_back(it.second);
        sort(temp.begin(), temp.end());
        while(k--){
            ans.push_back((mp.find(temp[k]))->first);
        }
        return ans;
    }
};