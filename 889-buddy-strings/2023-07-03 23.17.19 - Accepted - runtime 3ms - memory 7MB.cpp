class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int neq{};

        vector<int> sm(26, 0);
        vector<int> gm(26, 0);

        for(int i = 0; i < s.size(); i++) {
            neq += (s[i] != goal[i]);
            if(++sm[s[i] - 'a'] == 2 && s == goal) return true;
            gm[goal[i] - 'a']++;
        }

        if(neq == 0 || neq > 2 || sm != gm) return false;
        return true;
    }
};