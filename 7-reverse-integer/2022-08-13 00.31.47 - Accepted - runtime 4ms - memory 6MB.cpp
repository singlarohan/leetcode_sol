class Solution {
public:
    int reverse(int x) {
        int k{};
        while(x != 0){
            if(k > INT_MAX/10 || k < INT_MIN /10)
            return 0;
            k = k*10 + x % 10;
            x = x/10;
        }
        return (int)k;
    }
};