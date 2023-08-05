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
        for(auto x:bits) cout<<x<<" ";
        int ans{};
        for(int i = 0; i < 31; i++){
            if(bits[i])
            ans += pow(2, i);
        }
        if(bits[31]) ans += INT_MIN;
        return ans;
    }
};