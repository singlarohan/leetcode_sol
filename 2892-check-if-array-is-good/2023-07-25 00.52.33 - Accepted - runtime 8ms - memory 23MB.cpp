class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> hash(n + 1, 1);
        hash[n]++;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] <= 0 || nums[i] > n || hash[nums[i]]-- == 0) return false;
        return true;
    }
};