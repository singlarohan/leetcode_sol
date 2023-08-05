class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once{},twice{};
        for(auto &n:nums){
            once = once ^ n;
            once = once & (~twice);
            twice = twice ^ n;
            twice = twice & (~once);
        }
        return once;
    }
};