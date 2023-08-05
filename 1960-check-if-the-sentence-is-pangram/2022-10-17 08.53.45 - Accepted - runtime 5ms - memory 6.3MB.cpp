class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> alph (26, false);
        for(auto &c: sentence)
            alph[c - 'a'] = true;
        vector<bool> alph2(26, true);
        return alph == alph2;
    }
};