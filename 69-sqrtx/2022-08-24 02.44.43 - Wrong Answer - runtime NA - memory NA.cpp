class Solution {
public:
    int mySqrt(int x) {
        float i = 1, j = x;
        while(j - i > 0.1){
            j = (j+i)/2;
            i = x/j;
        }
        return (int)j;
    }
};