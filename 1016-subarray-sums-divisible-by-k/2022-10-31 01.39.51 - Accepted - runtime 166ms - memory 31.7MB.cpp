class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int sum{}, ans{};
        for(int i = 0; i < nums.size(); i++){
            sum = (sum + nums[i]);
            if(sum < 0)
                sum = k - ((-sum) % k);
            sum %= k;
            if(mp.find(sum) != mp.end())
                ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};