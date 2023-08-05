class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> alph (26, false);
        for(auto &c: sentence)
            alph[c - 'a'] = true;
        return alph == vector<bool> (26, true);
    }
};