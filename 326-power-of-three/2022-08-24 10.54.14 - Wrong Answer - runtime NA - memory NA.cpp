class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
       int i = log(n)/log(3);
       return (n-pow(3,i) == 0);
    }
};