class Solution {
public:
    int divide(long long dividend, int divisor) {
        //using bitwise operation
        //observe that x >> i == x/pow(2,i)
        // and that    x << i == x*pow(2,i)
        
        bool Pos = !((dividend < 0 && divisor > 0) ||(dividend > 0 && divisor < 0));
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long ans{0};
        
        for(int i = 31; i >= 0 && ans <= INT_MAX && dividend >= divisor; i--){
            long long temp = (long long)divisor << i;
            if(temp <= dividend){
                ans += (long long)1 << i;
                dividend -= temp;
            }
        }
        if(Pos)
            return min((long long)INT_MAX, ans);
        return max((long long)INT_MIN, -ans);
    }
};