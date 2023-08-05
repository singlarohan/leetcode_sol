class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev{INT_MIN};
        for(int i = 0; i < s.size(); i++){
            int curr{};
            if(s[i] - '0' >=0 && s[i] - '0' <= 9){
                while(i < s.size() && s[i] - '0' >=0 && s[i] - '0' <= 9){
                    curr = curr*10 + s[i] - '0';
                    i++;
                }
                if(prev < curr)
                    prev = curr;
                else
                    return false;
            }
        }
        return true;
    }
};