class Solution {
public:

    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1)
        return "";
        for(int i = 0; i < palindrome.size(); i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                break;
            }
            if(i == palindrome.size() - 1)
            palindrome[i] = 'b';
        }
        return palindrome;
    }
};