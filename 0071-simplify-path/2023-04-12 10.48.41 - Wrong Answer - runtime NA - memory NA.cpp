class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        string temp;
        for(int i = 1; i < path.size(); i++){
            if(path[i] == '/'){
                if(temp == ".");
                else if(temp == ".."){
                    while(ans.back() != '/') ans.pop_back();
                }
                else if(temp.empty()) continue;
                else ans += temp;
                ans.push_back('/');
                temp.clear();
            }
            else temp.push_back(path[i]);
        }
        if(ans.size() != 1 && ans.back() == '/') ans.pop_back();
        return ans;
    }
};