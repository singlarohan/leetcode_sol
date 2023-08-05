class Solution {
public:
    int minimumLength(string s) {
        int begin = 0, end = s.size() - 1;
        while(begin < end){
            if(s[begin] == s[end]){
                while(begin < end && s[begin] == s[begin + 1])
                    begin++;
                while(begin < end && s[end - 1] == s[end])
                    end--;
                // if(begin == end)
                //     return 0;
                begin++, end--;
            }
            else
                break;
        }
        return end < begin ? 0 : end - begin + 1;
    }
};