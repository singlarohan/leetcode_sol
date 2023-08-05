class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 1)
            return dividend;
        double ans;
        bool sign = 1;
        double dividend1 = dividend;
        if(divisor < 0 && dividend > 0 || divisor > 0 && dividend < 0)
            sign = 0;
        dividend1 = abs(dividend1);
        divisor = abs(divisor);
        while(dividend1 >= divisor){
            dividend1 -= divisor;
            ans++;
            if(ans > INT_MAX)
                break;
        }
        if(sign){
            if(ans >= INT_MAX)
                return INT_MAX;
            return (int)ans;
        }
        if(ans >= INT_MAX)
            return INT_MIN;
        return (int)-ans;
    }
};