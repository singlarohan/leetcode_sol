class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n <= 0)
        //     return false;
        // int i = log2((n)) / 2;
        // if(pow(4, i) == n)
        //     return true;
        // return false;
        //using log and pow function
        
        //using loops
        if(n <= 0)
            return false;
        while(n != 1){
            if(n % 4 != 0)
                return false;
            n /= 4;
        }
        return true;
    }
};