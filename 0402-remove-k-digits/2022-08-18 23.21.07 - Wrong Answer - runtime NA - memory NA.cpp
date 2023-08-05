class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size())
            return "0";
        string s;
        for(int i = 0; i < num.size(); i++){
            if(k == 0){
                s.push_back(num[i]);
                continue;
            }
            if(s.empty())
                s.push_back(num[i]);
            else{
                if(s.back() > num[i]){
                    s.pop_back();
                    s.push_back(num[i]);   
                }
                k--;
            }
            if(s.size() == 1 && s.back() == '0')
                s.pop_back();
        }
        if(s.empty())
            return "0";
        return s;
    }
};