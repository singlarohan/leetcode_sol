class Solution {
public:

    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1)
        return "";
        for(int i = 0; i < n/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                break;
            }
            if(i == n / 2 - 1)
            palindrome[i] = 'b';
        }
        return palindrome;
    }
};