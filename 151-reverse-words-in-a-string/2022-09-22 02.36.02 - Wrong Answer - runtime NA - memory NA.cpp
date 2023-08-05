class Solution {
public:
    void rev_erse(int i, int j, string &s){
        while(i < j){
            swap(s[i], s[j]);
            i++, j--;
        }
    }
    
    void remove_space(string &s){
        int j{};
        for(int i = 0; i < s.size(); i++, j++){
            if(s[i] == ' '){
                if(i) j++;
                while(i < s.size() - 1 && s[i] == ' ') i++;
            }
            swap(s[i], s[j]);
        }
        while(s[s.size() - 1] == ' ')
            s.pop_back();
    }
    
    string reverseWords(string s) {
        int end = s.size() - 1, start;
        for(int i = s.size() - 1; i>=0; i--){
            while(i >= 0 && s[i] == ' ')
                i--;
            end = i;
            while(i >= 0 && s[i] != ' ')
                i--;
            start = i + 1;
            rev_erse(start, end, s);
        }
        reverse(s.begin(), s.end());
        remove_space(s);
        return s;
    }
};