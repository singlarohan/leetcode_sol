class Solution {
public:
    int largestVariance(string s) {
        //let's see if between letter 'a' and 'b'
        //wherever number of a > b drop it there
        int ans = 0;
        for(char c = 'a'; c <= 'z'; c++){
            for(char d = 'a'; d <= 'z'; d++){
                bool flag = false;
                int a = 0, b = 0;
                for(int i = 0; i < s.size(); i++){
                    if(s[i] == c) a++;
                    if(s[i] == d) b++;
                    
                    if(b > a) a = b = 0;
                    else if(b != 0) ans = max(ans, a - b);
                }
            }
        }
        return ans;
    }
};