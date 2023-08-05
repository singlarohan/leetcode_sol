class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long count{};
        long long ans1{}, ans2{};
        //ans1 if a is added to beginning;
        for(int i = 0; i < text.size(); i++){
            if(text[i] == pattern[0]) count += 1;
            else if(text[i] == pattern[1]) {
                ans1 += 1 + count;
                ans2 += count;
            }
        }
        ans2 += count;
        if(pattern[0] == pattern[1]) return (count*(count + 1))/2;
        return max(ans1,ans2);
        //two iterations
        //if a is added at beginning;
    }
};