class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr{};
        long long sum{};
        //count set bits
        // % 3 we get our answer
        vector<int> bits(32, 0);
        for(int i = 0; i < nums.size(); i++){
            int t = 1;
            for(int x = 0; x < 32; x++){
                if(nums[i] & t) {
                    bits[x]++;
                    bits[x] %= 3;
                }
                if(x != 31)
                t = t << 1;
            }
        }
        int ans{};
        for(int i = 0; i < 32; i++)
            if(bits[i]) ans |= 1 << (i);
        return ans;
    }
};