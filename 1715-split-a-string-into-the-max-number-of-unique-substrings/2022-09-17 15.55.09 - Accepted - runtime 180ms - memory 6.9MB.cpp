class Solution {
public:
    unordered_map<string, bool> mp;
    
    int solve(int i, string &s){
        if(i >= s.size())
            return 0;
        int ans{};
        string temp;
        for(int j = i; j < s.size(); j++){
            temp.push_back(s[j]);
            if(!mp[temp]){
                mp[temp] = true;
                ans = max(ans, 1 + solve(j+1, s));
                mp[temp] = false;
            }
        }
        return ans;
    }
    
    int maxUniqueSplit(string s) {
        return solve(0, s);
    }
};