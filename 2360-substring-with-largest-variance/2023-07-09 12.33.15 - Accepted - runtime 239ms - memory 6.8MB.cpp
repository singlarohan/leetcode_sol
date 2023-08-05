class Solution {
public:
    int largestVariance(string s) {
        vector<int> mp(26, 0);
        for(auto c:s) mp[c - 'a']++;
        //let's see if between letter 'a' and 'b'
        //wherever number of a > b drop it there
        int ans = 0;
        for(char c = 'a'; c <= 'z'; c++){
            for(char d = 'a'; d <= 'z'; d++){
                //in this loop we are check with c -> major element
                //                               d -> minor element of the substring
                if(mp[c - 'a'] == 0 || mp[d - 'a'] == 0 || c == d) continue;
                
                bool flag = false;
                //this flag will tell us if we have 
                //a letter d before the combinations of letter c
                //prior to include in case we get like a = 2, b = 0
                //flag tells us if we can add a substring from before

                int a = 0, b = 0;

                for(int i = 0; i < s.size(); i++){
                    if(s[i] == c) a++;
                    if(s[i] == d) b++;

                    if(b > a) {
                        flag = true;
                        a = b = 0;
                    }
                    else if(b != 0) ans = max(ans, a - b);
                    else if(flag) ans = max(ans, a - 1);
                }
            }
        }
        return ans;
    }
};