class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size())
            return "0";
        if(k == 0)
            return num;
        stack<char> s;
        for(int i = 0; i < num.size(); i++){
            while(k > 0 && !s.empty() && s.top() > num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
            if(s.size() == 1 && s.top() == '0')
                s.pop();
        }
        while(!s.empty() && k > 0){
            s.pop();
            k--;
        }
        if(s.empty())
            return "0";
        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};