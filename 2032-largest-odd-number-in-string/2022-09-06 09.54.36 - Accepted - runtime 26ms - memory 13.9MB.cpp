class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--, num.pop_back())
            if((num[i] - '0') % 2 != 0)
                break;
        return num;
    }
};