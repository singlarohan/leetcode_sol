class Solution {
public:
    int minimumMoves(string s) {
        int ans{};
        for(int i = 0; i < s.size(); i++)
            if(s[i] == 'X') ans++, i += 2;
        return ans;
    }
};