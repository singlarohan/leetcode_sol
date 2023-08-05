class Solution {
public:
    int countVowelStrings(int n) {
        int a,b,c,d,e;
        a = b = c = d = e = 1;
        for(int i = 0; i < n; i++){
            a = a + b + c + d + e;
            b = b + c + d + e;
            c = c + d + e;
            d = d + e;
            e = e;
        }
        return a;
    }
};