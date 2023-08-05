class Solution {
public:
    string base_rem(int n, int base){
        string temp;
        while(n != 0){
            temp += to_string(n % base);
            n /= base;
        }
        return temp;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n - 2; i++){
            string temp1 = base_rem(n, i);
            string temp2 = temp1;
            reverse(temp2.begin(), temp2.end());
            if(temp1 != temp2)
                return false;
        }
        return true;
    }
};