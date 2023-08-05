class Solution {
public:
    int myAtoi(string s) {
        bool ifneg{false}, flag{false};
        double ans{0};
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '-' && !flag)
                ifneg = true;
            else if(s[i] >= '0' && s[i] <= '9'){
                ans = ans * 10 + (s[i] - 48);
                if(!flag)
                flag = true;
            }
            else{
                if(!flag && s[i] == ' ');
                else
                    break;
            }
        }
        if(ans > INT_MAX && ifneg)
            return INT_MIN;
        if(ans > INT_MAX && !ifneg)
            return INT_MAX;
        if(ifneg)
            return (int) ans*-1;
        return (int)ans;
        
    }
};