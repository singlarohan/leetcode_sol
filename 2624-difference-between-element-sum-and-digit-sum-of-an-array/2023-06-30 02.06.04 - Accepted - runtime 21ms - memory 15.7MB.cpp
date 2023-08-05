class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elsum{};
        int digsum{};
        for(auto x:nums){
            elsum += x;
            while(x != 0){
                digsum += x % 10;
                x /= 10;
            }
        }
        return abs(elsum - digsum);
    }
};