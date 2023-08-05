class Solution {
public:
    string addBinary(string a, string b) {
        // int a1, int b1;
        // for(int i = a.size() - 1; i>=0; i++){
        //     if(s[i] == '1')
        //         a1 += pow(2,a.size() - i - 1);
        // }
        // for(int i = b.size() - 1; i>=0; i++){
        //     if(s[i] == '1')
        //         b1 += pow(2,b.size() - i - 1);
        // }
        // int ans = a1 + b1;
        string ans;
        bool carry{0};

        for(int i = a.size() - 1, j = b.size() - 1;; i--, j--){
            if(i < 0 && j < 0)
                break;
            else if(i < 0){
                if(b[j] == '1'){
                    if(carry)
                        ans.push_back('0');
                    else{
                        ans.push_back('1');
                    }
                }
                if(b[j] == '0'){
                    if(carry){
                        ans.push_back('1');
                        carry = false;
                    }
                    else{
                        ans.push_back('0');
                    }
                }
            }
            else if(j < 0){
                if(a[i] == '1'){
                    if(carry)
                        ans.push_back('0');
                    else{
                        ans.push_back('1');
                    }
                }
                if(a[i] == '0'){
                    if(carry){
                        ans.push_back('1');
                        carry = false;
                    }
                    else{
                        ans.push_back('0');
                    }
                }
            }
            else if(a[i] == '1' && b[j] == '1'){
                if(carry)
                    ans.push_back('1');
                else
                    ans.push_back('0');
                carry = true;
            }
            else if(a[i] == '0' && b[j] == '0'){
                if(carry)
                    ans.push_back('1');
                else
                    ans.push_back('0');
                carry = false;
            }
            else{
                if(carry)
                    ans.push_back('0');
                else
                    ans.push_back('1');
            }
        }
        if(carry)
            ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};