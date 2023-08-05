class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // we xor everything
        int ans{};
        for(auto &x:nums) ans ^= x;
        return ans;
    }
};