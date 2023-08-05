class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans{};
        // unordered_map<int, bool> mp;
        // for(int i = 0; i < nums.size(); i++)
        //     mp[nums[i]] = true;
        // for(int i = 1;  k; i++){
        //     if(!mp[i])
        //         ans += i, k--;
        // }
        sort(nums.begin(), nums.end());
        int temp = 1;
        for(int i = 0; i < nums.size() && k > 0; i++){
            if(temp == nums[i] + 1)
                continue;
            int n = min(nums[i] - temp, k);
            int f = temp;
            int l = min(nums[i] - 1, temp + k - 1);
            ans += (long long)(f + l)* n / 2;
            temp = nums[i] + 1;
            k -= n;
        }
        if(k > 0){
            int f = nums.back() + 1;
            int l = f + k - 1;
            ans += k * (long long)(f + l) / 2;
        }
        return ans;
    }
};