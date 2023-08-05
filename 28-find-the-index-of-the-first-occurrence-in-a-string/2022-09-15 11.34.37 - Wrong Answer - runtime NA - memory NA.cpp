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
            if(count == 0){
                count = needle.size() - 1;
                ans = i - 1;
            }
        }
        return ans;
    }
};