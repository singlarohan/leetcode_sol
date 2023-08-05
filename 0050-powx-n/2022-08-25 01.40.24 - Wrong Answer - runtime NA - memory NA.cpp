class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1)
            return 1;
        if(n == INT_MIN)
            return 0;
        double ans = {x};
        double rem = {1};
        int num = abs(n);
        while(num > 1){
            if(num % 2 == 0){
                ans *= ans;
                x = ans;
                num = num / 2;
            }
            else{
                rem *= x;
                num--;
            }
        }
        if(n < 0)
            return 1/(rem*ans);
        return rem*ans;  
    }
};