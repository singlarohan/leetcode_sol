class Solution {
public:
    int reverse(int x) {
        double k{};
        while(x != 0){
            k *= 10;
            k += x%10;
            x = x/10;
            if(k > INT_MAX || k < INT_MIN)
                break;
        }
        if(k > INT_MAX)
           return INT_MAX;
        if(k < INT_MIN)
            return INT_MIN;
        return (int)k;
    }
};