class Solution {
public:
    int reverse(int x) {
        double k{};
        while(x != 0){
            k *= 10;
            k += x%10;
            x = x/10;
            if(k > INT_MAX || k < INT_MIN)
                return 0;
        }
        return (int)k;
    }
};