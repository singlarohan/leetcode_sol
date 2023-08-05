class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1)
            return 1;
        double ans = {1};
        while(n < 0){
            ans /= x;
            n++;
        }
        while(n > 0){
            ans *= x;
            n--;
        }
          return ans;  
    }
};