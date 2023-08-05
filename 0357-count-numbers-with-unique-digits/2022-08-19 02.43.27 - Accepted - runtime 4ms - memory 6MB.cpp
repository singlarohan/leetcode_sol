class Solution {
public:
    int perm(int n, int r){
        if(r == 0)
            return 1;
        return n*perm(n-1, r-1);
    }
    
    int countNumbersWithUniqueDigits(int n) {
        int ans{};
        for(int i = 0; i<n; i++){
            ans += perm(9, i); 
        }
        // ans *= 9;
        return 9 * ans + 1;
    }
};