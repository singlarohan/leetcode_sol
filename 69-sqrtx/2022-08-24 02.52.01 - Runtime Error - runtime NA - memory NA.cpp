class Solution {
public:
    int mySqrt(int x) {
        int i = 1, j = x;
        while(j > i){
            j = (j+i)/2;
            i = x/j;
        }
        // int temp = (int)j * (int)j;
        // if(temp > x)
        //     return (int)j - 1;
        return j;
    }
};