class Solution {
public:
    string fractionToDecimal(int num, int den) {
        unordered_map<int, int> mp;
        string ans = "";
        if(num < 0){
            ans += '-';
            num = abs(num);
        }
        if(num < den)
            ans += "0";

        else{
            ans += to_string(num/den);
            num %= den;
        }
        string temp;
        while(num != 0){
            if(mp[num] != 0)
                break;
            mp[num] = temp.size() + 1;
            num *= 10;
            if(den > num){
                temp.push_back('0');
                continue;
            }
            else{
                temp.push_back(num/den + '0');
                num %= den;
            }
        }
        if(temp.empty())
            return ans;
        if(num == 0)
            return ans + '.' + temp;
        ans += '.';
        for(int i = 0; i < temp.size(); i++){
            if(i == mp[num] - 1)
                ans += '(';
            ans += temp[i];
        }
        ans += ')';
        return ans;
    }
};