class Solution {
public:
    int stringtoINT(string s){
        int n{0};
        for(int i = 0; i<s.size(); i++){
            n *= 10;
            n += s[i] - '0';
        }
        return n;
    }
    
    string INTtostring(int n){
        string s;
        if(n == 0)
            return "0";
        while(n != 0){
            s.push_back(n%10 + '0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
    string multiply(string num1, string num2) {
        int numb1 = stringtoINT(num1);
        int numb2 = stringtoINT(num2);
        string s = INTtostring(numb1 * numb2);
        return s;
    }
};