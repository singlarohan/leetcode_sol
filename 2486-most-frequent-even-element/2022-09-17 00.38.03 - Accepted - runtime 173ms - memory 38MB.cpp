class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        pair<int, int> ans = {-1,0};
        for(int i = 0; i < nums.size(); i++){
            if(!(nums[i] % 2)){
                mp[nums[i]]++;
                if(mp[nums[i]] > ans.second)
                    ans = {nums[i], mp[nums[i]]};
                else if(mp[nums[i]] == ans.second)
                    ans.first = min(ans.first, nums[i]);
            }
        }
        return ans.first;
    }
};