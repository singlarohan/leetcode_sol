class Solution {
public:
    vector<bool> used;
    string temp;
    string ans; 
    
    void solve(int i, string pattern){
        if(i == pattern.size()){
            ans = min(ans, temp);
            return;
        }
        if(temp > ans) return;
        for(int j = 1; j < 10; j++){
            if(!used[j])
            if(i == -1 || (pattern[i] == 'I' && j > temp.back() - '0') || (pattern[i] == 'D' && j < temp.back() - '0')){
                temp.push_back(j + '0');
                used[j] = true;
                solve(i+1, pattern);
                used[j] = false;
                temp.pop_back();
            }
        }
    }
    
    string smallestNumber(string pattern) {
        used = vector<bool> (10, false);
        ans = "99";
        temp = "";
        solve(-1, pattern);
        return ans;
    }
};