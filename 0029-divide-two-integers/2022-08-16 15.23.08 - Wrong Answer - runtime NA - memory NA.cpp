class Solution {
public:
    int divide(int dividend, int divisor) {
        double ans;
        bool sign = 1;
        if(divisor < 0 && dividend > 0){
            sign = 0;
            divisor = -divisor;
        }
        else if(divisor > 0 && dividend < 0){
            sign = 0;
            dividend = -dividend;
        }
        else if(divisor < 0 && dividend < 0){
            sign = 1;            
            divisor = -divisor;
            dividend = -dividend;
        }
        while(dividend > divisor){
            dividend -= divisor;
            ans++;
            if(ans > INT_MAX)
                break;
        }
        if(sign){
            if(ans > INT_MAX)
                return INT_MAX;
            return (int)ans;
        }
        if(ans > INT_MAX)
            return INT_MIN;
        return (int)-ans;
    }
};