class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i=1;i<=n;i++)
        {
            int shift = 1 + log2(i);
            ans = ((ans<<shift)+i)%1000000007;
        }
        return ans;
    }
};