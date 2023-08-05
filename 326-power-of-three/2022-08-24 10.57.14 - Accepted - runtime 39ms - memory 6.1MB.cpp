class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
       int i = 1.0*log(n)/(1.0*log(3)) + 0.00001;
       return (n-pow(3,i) == 0);
    }
};