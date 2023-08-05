class Solution {
public:
    int addMinimum(string word) {
        int ans{};
        //for word[0]
        ans += word[0] - 'a';
        for(int i = 1; i < word.size(); i++){
            if(word[i] <= word[i - 1]){
                ans += 'c' - word[i - 1];
                ans += word[i] - 'a';
            }
            else ans += word[i] - word[i - 1] - 1;
        }
        ans += 'c' - word.back();
        return ans;
    }
};