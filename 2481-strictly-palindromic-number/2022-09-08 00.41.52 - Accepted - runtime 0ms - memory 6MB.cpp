class Solution {
public:
    string base_rem(int n, int base){
        string temp;
        while(n != 0){
            temp += to_string(n % base);
            n /= base;
        }
        return temp;
    }
    bool isPalindrome(string S){
        int i = 0, j = S.size() - 1;
        while(i < j){
            if(S[i] != S[j])
                return false;
            i++, j--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n - 2; i++){
            if(!isPalindrome(base_rem(n, i)))
                return false;
        }
        return true;
    }
};