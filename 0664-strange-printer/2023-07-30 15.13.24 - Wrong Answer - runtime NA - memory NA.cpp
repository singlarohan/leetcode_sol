class Solution {
public:
    int solve(int l, int r, string &s){
        if(l >= r) return l == r;

        int ans = 0;
        char start = s[l], end = s[r];

        if(start == end){
            while(l <= r && s[l] == start) l++;
            while(r >= l && s[r] == end) r--;

            ans = 1 + solve(l, r, s);
        }
        else{
            int new_l = l;
            while(new_l <= r && s[new_l] == start) new_l++;
            int new_r = r;
            while(new_r >= l && s[new_r] == end) new_r--;

            ans = 1 + min(solve(new_l, r, s), solve(l, new_r, s));
            
        }
        return ans;
    }
    int strangePrinter(string s) {
        return solve(0, s.size() - 1, s);
    }
};