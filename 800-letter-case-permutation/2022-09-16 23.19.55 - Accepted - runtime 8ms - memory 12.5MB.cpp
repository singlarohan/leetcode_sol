class Solution {
public:
    vector<string> ans;
    
    void solve(string &s, int i, string &temp){
        if(i >= s.size()){
            ans.push_back(temp);
            return;
        }
        if(s[i] >= '0' && s[i] <= '9'){
            temp.push_back(s[i]);
            solve(s, i + 1, temp);
            temp.pop_back();
        }
        else{
            if(s[i] < 'a'){
                temp.push_back(s[i]);
                solve(s, i+1, temp);
                temp.pop_back();
                temp.push_back(s[i] - 'A' + 'a');
                solve(s, i+1, temp);
                temp.pop_back();
            }
            else{
                temp.push_back(s[i]);
                solve(s, i+1, temp);
                temp.pop_back();
                temp.push_back(s[i] - 'a' + 'A');
                solve(s, i+1, temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        string temp;
        solve(s, 0, temp);
        return ans;
        
    }
};