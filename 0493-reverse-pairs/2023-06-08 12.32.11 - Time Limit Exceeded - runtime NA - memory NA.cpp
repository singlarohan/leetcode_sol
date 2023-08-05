class Solution {
public:
    int reversePairs(vector<int>& nums) {
        map<int, int> mp;
        // cout<<nums.size()<<endl;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        int ans{};
        for(int i = nums.size() - 1; i > 0; i--){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            for (auto it = mp.rbegin(); it != mp.rend() 
                && (long long)(it -> first) > 2 * (long long)nums[i]; ++it)
                ans += (it -> second);
        }
        return ans;
    }
};