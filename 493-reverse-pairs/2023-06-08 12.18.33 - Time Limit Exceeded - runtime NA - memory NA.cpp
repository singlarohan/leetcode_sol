class Solution {
public:
    int reversePairs(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);
        int ans{};
        for(int i = nums.size() - 1; i > 0; i--){
            mp[nums[i]].pop_back();
            if(mp[nums[i]].empty()) mp.erase(nums[i]);
            for (auto it = mp.rbegin(); it -> first > 2 * nums[i]; ++it){
                ans += (it -> second).size();
            }
        }
        return ans;
    }
};