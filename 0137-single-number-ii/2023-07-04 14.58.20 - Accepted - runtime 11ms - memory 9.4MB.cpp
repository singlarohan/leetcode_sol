class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once{},twice{};
        for(auto &n:nums){
            once ^= n;
            once &= (~twice);
            twice ^= n;
            twice &= (~once);
        }
        return once;
    }
};