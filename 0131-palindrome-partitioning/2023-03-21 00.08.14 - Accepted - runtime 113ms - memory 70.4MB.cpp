class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        auto ifpalin = [&](int i, int j, auto &&self){
            if(i >= j) return 1;
            if(s[i] != s[j]) return 0;
            return self(i + 1, j - 1, self);
        };
        auto solve = [&](int i, int j, auto &&self){
            if(j == s.size()){
                if(ifpalin(i, j - 1, ifpalin))
                ans.push_back(temp);
                return;
            }
            if(ifpalin(i, j - 1, ifpalin)){
                string a = "";
                a += s[j];
                temp.push_back(a);
                self(j, j + 1, self);
                temp.pop_back();
            }
            temp.back().push_back(s[j]);
            self(i, j + 1, self);
            temp.back().pop_back();

        };
        string t = "";
        t += s[0];
        temp.push_back(t);
        solve(0, 1, solve);
        return ans;
    }
};