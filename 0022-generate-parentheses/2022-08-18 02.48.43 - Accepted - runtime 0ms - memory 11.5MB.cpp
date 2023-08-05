class Solution {
public:
    void solve(int i, int j, int n, vector<string> &ans, string &temp){
        if(i < 0 || j < i)
            return;
        if(i == 0 && j == 0)
            ans.push_back(temp);
        temp.push_back('(');
        solve(i - 1, j, n, ans, temp);
        temp.pop_back();
        temp.push_back(')');
        solve(i, j - 1, n, ans, temp);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        solve(n, n, n, ans, temp);
        return ans;
    }
};