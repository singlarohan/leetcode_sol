class Solution {
public:

    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1)
        return "";
        for(int i = 0; i < n; i++){
            if(palindrome[i] != 'a' && (n % 2 == 0 || i != n / 2)){
                palindrome[i] = 'a';
                break;
            }
            if(i == n - 1)
            palindrome[i] = 'b';
        }
        return palindrome;
    }
};