class Solution {
public:
    double myPow(double x, int n) {
        //for negative powers and positive powers differntly
        if(n == 0 || x == 1) return 1;
        if(x == -1) return n % 2 == 0 ? 1 : -1;
        // if(n == INT_MIN) return 0;
        bool flag = n < 0;
        n = abs(n);
        double rem = 1;
        while(n > 1){
            if(n % 2 == 0){
                x *= x;
                n /= 2;
            }
            else{
                rem *= x;
                n--;
            }
        }
        return flag ? 1/(rem * x) : rem * x;
    }
};