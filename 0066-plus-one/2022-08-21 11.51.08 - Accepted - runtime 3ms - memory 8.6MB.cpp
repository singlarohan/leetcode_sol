class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // reverse(digits.begin(), digits.end());
        // int carry{};
        // digits[0] += 1;
        // for(int i = 0; i< digits.size(); i++){
        //     digits[i] += carry;
        //     carry = digits[i]/10;
        //     digits[i] %= 10;
        // }
        // if(carry)
        //     digits.push_back(carry);
        // reverse(digits.begin(), digits.end());
        // return digits;
        int n = digits.size();
        digits[n-1]++;
        if(digits[n-1] <= 9)
            return digits;
        int i{n-2}, carry = 1; digits[n-1] = 0;
        while(i >= 0){
            if(carry == 0)
                break;
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            i--;
        }
        if(!carry)
            return digits;
        else{
            digits.clear();
            digits.push_back(1);
            while(n--)
                digits.push_back(0);
        }
        return digits;
    }
};