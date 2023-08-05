class Solution {
public:
    bool powerFive(int num){
        return (pow(5, (int)(log2(num) / log2(5))) == num);
    }
    int solve(int i, string &s, int curr){
        if(i > s.size()) return powerFive(curr) ? 0 : 1e9;
        
        int ans = solve(i + 1, s, (curr << 1) + (s[i] == '1'));
        
        if(s[i] != '0' && curr != 0 && powerFive(curr)) ans = min(ans, 1 + solve(i + 1, s, 1));
        
        return ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        if(s[0] == '0') return -1;
        
        int ans = solve(0, s, 0);
        return ans >= 1e8 ? -1 : ans;
    }
};