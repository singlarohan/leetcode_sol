class Solution {
public:
    int addMinimum(string word) {
        int ans = 0, i = 0;
        while(i < word.size()){
            (word[i] == 'a') ? i++ : ans++;         
            (word[i] == 'b') ? i++ : ans++;
            (word[i] == 'c') ? i++ : ans++;
        }
        return ans;
    }
};