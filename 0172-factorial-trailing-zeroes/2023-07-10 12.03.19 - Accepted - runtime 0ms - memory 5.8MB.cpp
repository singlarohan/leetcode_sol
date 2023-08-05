class Solution {
public:
    int trailingZeroes(int n) {
        int ans{}, num = 5, curr = 1;

        while(curr != 0){
            curr = n / num;
            num *= 5;
            ans += curr;
        }

        return ans;
    }
};