class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> s = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, int> mp;
        for(int i = 0; i<words.size(); i++){
            string temp;
            for(int j = 0; j < words[i].size(); j++){
                temp += s[words[i][j] - 'a'];
            }
            mp[temp] = 1;
        }
        int ans{0};
        for(auto it:mp){
            ans += it.second;
        }
        return ans;
    }
};