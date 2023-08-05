class Solution {
public:
    int strStr(string haystack, string needle) {
        // int count = needle.size() - 1;
        // int ans{-1};
        // for(int i = haystack.size() - 1; i >= 0; i--){
        //     if(haystack[i] != needle[count])
        //         count = needle.size() - 1;
        //     if(haystack[i] == needle[count])
        //         count--;
        //     if(count == -1){
        //         count = needle.size() - 1;
        //         ans = i;
        //     }
        // }
        // count = 0;
        // for(int i = 0; i < haystack.size(); i++){
        //     if(haystack[i] != needle[count])
        //         count = 0;
        //     if(haystack[i] == needle[count])
        //         count++;
        //     if(count == needle.size())
        //         return i - count + 1;
        // }
        // return ans;
        //fucking brute force
        for(int i = 0; i < haystack.size(); i++){
            int j = 0;
            while(j < needle.size() && needle[j] == haystack[i + j])
                j++;
            if(j == needle.size())
            return i;
        }
        return -1;
    }
};