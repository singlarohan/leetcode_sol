class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(k == 0)
                break;
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};