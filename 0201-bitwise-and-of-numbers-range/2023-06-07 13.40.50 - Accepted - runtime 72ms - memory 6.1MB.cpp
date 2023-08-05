class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // cout<<log2(left)<<" "<<log2(right);
        if(!left || !right || (int)log2(left) != (int)log2(right)) return 0;
        int ans = left;
        for(long m = left; m <= right; m++)
        ans &= m;
        return ans;
    }
};