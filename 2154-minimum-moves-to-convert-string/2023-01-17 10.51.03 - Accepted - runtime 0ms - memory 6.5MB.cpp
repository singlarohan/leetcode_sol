class Solution {
public:
    int minimumMoves(string s) {
        int ans{}, i{};
        while(i < s.size() && s[i] == '0') i++;
        for(i; i < s.size(); i++)
            if(s[i] == 'X') ans++, i += 2;
        return ans;
    }
};