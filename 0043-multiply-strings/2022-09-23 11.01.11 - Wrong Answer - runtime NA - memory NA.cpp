class Solution {
public:
    
    string multiply(string num1, string num2) {
        string s = "";
        for(int i = num2.size() - 1; i >= 0; i--){
            int carry{};
            for(int j = num1.size() - 1; j >= 0; j--){
                int temp = (num2[i] - '0') * (num1[j] - '0') + carry;
                if(num1.size() + num2.size() - i - j - 2 >= s.size())
                    s += (temp % 10 + '0');
                
                else{
                    temp += s[num1.size() + num2.size() - i - j - 2] - '0';
                    s[num1.size() + num2.size() - i - j - 2] = temp % 10 + '0';
                }
                carry = temp / 10;
            }
            if(carry)
                s.push_back(carry + '0');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};