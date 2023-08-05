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
        int temp{1};
        for(int i = 0; i < nums.size() && k; i++){
            while(temp < nums[i] && k){
                ans += temp;
                temp++;
                k--;
            }
            temp++;
        }
        while(k--){
            ans += temp;
            temp++;
        }
        return ans;
    }
};