class Solution {
public:
    int help(int n, int d){
        while(n % d == 0)
            n /= d;
        return n;
    }
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        if(help(help(help((n), 2), 3), 5) == 1)
            return true;
        return false;
    }
};