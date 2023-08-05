class Solution {
public:
    // no. of bits = log2(n) + 1
    int M = 1000000007;
    
    long long power(int x, unsigned int y)
    {
        if (y == 0)
            return 1;
        long long temp;
        temp = power(x, y / 2);
        if (y % 2 == 0)
            return (temp * temp) % M;
        else
            return (x * temp * temp) % M;
    }
    
    int concatenatedBinary(int n) {
        long long extra_bits{}, ans{};
        long long curr{1};
        for(long long i = n; i > 0; i--){
            // ans = (ans + i * power(2, extra_bits)) % M;
            ans = (ans + i * curr) % M;
            // extra_bits += log2(i) + 1;
            curr = (curr << (long long)(log2(i) + 1)) % M;
        }
        return ans % M;
    }
};