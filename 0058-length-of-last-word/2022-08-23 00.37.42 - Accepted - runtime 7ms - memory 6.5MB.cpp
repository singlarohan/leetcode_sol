class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(s[i] == ' ')
            i--;
        int count{};
        while(i>=0 && s[i] != ' ')
            count++, i--;
        return count;
    }
};