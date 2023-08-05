class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count{};
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                count++;
            if(s[i] == ')'){
                if(count == 0)
                    s[i] = "";
                else
                    count--;
            }
        }
        for(int i = s.size() - 1; i>=0 && count != 0; i--){
            if(s[i] == '('){
                s.erase(i, 1);
                s[i] = "";
                count--;
            }
        }
        string temp;
        for(auto x: s)
            if(x != '\0')
                temp.push_back(x);
        return temp;
    }
};