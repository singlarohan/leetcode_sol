class Solution {
public:
    int trailingZeroes(int n) {
        int ans{}, power = 1, curr = 1;

        for(int i = 1; curr != 0; i++){
            curr = n / pow(5, i);
            ans += curr;
            power++;
        }

        return ans;
    }
};