class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //using sorting and hashing
        vector<int> ans;
        vector<int> mp(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i] - 1]++;
            if(mp[nums[i] - 1] == 2)
                ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++)
            if(mp[i] == 0)
                ans.push_back(i + 1);
        return ans;
    }
};