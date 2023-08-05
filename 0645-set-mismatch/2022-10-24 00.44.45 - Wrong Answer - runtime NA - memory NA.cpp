class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //using sorting and hashing
        vector<int> ans;
        vector<int> mp(nums.size(), 0);
        //instead of extra space we can store this
        //in the nums array itself
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
            else
                ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                ans.push_back(i + 1);
        return ans;
    }
};