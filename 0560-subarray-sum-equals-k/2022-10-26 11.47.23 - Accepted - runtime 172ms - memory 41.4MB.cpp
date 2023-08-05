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
        int ans{};
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(i) nums[i] = nums[i] + nums[i - 1];
            if(mp.find(nums[i] - k) != mp.end())
                ans += mp[nums[i] - k];
            if(nums[i] == k)
                ans++;
            mp[nums[i]]++;
        }
        return ans;
    }
};