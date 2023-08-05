class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int neq{};
        vector<int> sm(26, 0);
        vector<int> gm(26, 0);
        bool flag = false;
        for(int i = 0; i < s.size(); i++) {
            neq += (s[i] != goal[i]);
            if(++sm[s[i] - 'a'] == 2) flag = true;;
            gm[goal[i] - 'a']++;
        }

        if(neq > 2 || sm != gm || (neq == 0 && !flag)) return false;
        return true;
    }
};