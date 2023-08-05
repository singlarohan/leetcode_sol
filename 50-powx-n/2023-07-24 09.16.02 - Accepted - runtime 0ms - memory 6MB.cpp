class Solution {
public:
    double raise(double x, int n){
        if(n == 0) return 1;

        return n % 2 == 0 ? raise(x * x, n / 2) : x * raise(x * x, n / 2);
    }
    double myPow(double x, int n) {
        double ans = raise(x, n);
        return n < 1 ? 1/ans : ans;
    }
};