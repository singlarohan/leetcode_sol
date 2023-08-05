class Solution {
public:
    string simplifyPath(string path) {
        string temp = "";
        string ans = "";
        int count{};
        for(int i = path.size() - 1; i >= 0; i--){
            if(path[i] != '/')
                temp += path[i];

            else{
                while(i && path[i - 1] == '/')
                    i--;
                if(!temp.empty()){
                    if(temp == "..")
                        count++;
    
                    else if(temp != ".")
                        if(count == 0)
                            ans += temp + '/';
                        else
                            count--;

                    temp.clear();
                }
            }
        }
        if(ans.empty())
            return "/";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};