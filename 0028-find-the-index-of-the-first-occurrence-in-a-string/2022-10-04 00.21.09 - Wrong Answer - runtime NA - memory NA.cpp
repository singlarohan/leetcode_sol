class Solution {
public:
    int strStr(string haystack, string needle) {
        int count = needle.size() - 1;
        int ans{-1};
        for(int i = haystack.size() - 1; i >= 0; i--){
            if(haystack[i] == needle[count])
                count--;
            else
                count = needle.size() - 1;
            if(count == -1){
                count = needle.size() - 1;
                ans = i;
            }
        }
        if(ans != -1)
        return ans;
        count = 0;
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[count])
                count++;
            else
                count = 0;
            if(count == needle.size())
                return i - count + 1;
        }
        return -1;
    }
};