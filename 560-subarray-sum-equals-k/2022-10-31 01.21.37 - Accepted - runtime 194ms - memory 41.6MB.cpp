class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int sum{nums[0]};
        // int ans{};
        // int i{0}, j{1};

        // while(j < nums.size()){
        //     if(k > sum){
        //         sum += nums[j];
        //         j++;
        //     }
        //     while(i<= j && k <= sum){
        //         if(k == sum)
        //         ans++;
        //         sum -= nums[i];
        //         i++;
                
        //     }
        // }
        // return ans;
        int ans{}, sum{};
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(mp.find(sum- k) != mp.end())
                ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};