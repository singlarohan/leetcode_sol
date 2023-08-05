class Solution {
public:
    void reve_rse(int start, int end, string &s){
        while(start < end){
            swap(s[start], s[end]);
            start++, end--;
        }
    }
    
    string reverseWords(string s) {
        for(int i = s.size() - 1; i >= 0; i--){
            int end = i;
            while(i >= 0 && s[i] != ' ')
                i--;
            int start = i + 1;
            reve_rse(start, end, s);
        }    
        return s;
    }
};