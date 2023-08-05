class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] - '0' >= 0 && s[i] - '0' < 10) temp += s[i];
            else if(isalpha(s[i]))
                temp += tolower(s[i]);
        }
        int l = 0, r = temp.size() - 1;
        while(l <= r)
            if(temp[l++] != temp[r--]) return false;
        return true;
    }
};