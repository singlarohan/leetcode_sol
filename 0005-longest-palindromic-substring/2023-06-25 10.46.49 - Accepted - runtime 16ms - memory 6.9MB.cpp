class Solution {
public:
    string longestPalindrome(string s) {
        //in n^2 it is easy
        //take a center iter in the other direction
        int n = s.size();
        pair<int, int> ans;
        for(int i = 0; i < s.size(); i++){
            int curr = 1;
            int l = i - 1;
            while(l >= 0 && 2 * i - l < n){
                if(s[l] == s[2*i - l]) curr += 2;
                else break;
                l--;
            }
            if(curr > ans.second) ans = {i, curr};
            //checking with even size substring
            curr = 0;
            if(i && s[i] == s[i - 1]){
                l = i - 2;
                curr = 2;
                while(l >= 0 && (2 * i - l - 1) < n){
                    if(s[l] == s[2*i - l - 1]) curr += 2;
                    else break;
                    l--;
                }
            }
            if(curr > ans.second) ans = {i, curr};
            // if(i == 12) cout<<curr<<endl;
        }
        // cout<<ans.first<<" "<<ans.second;
        string res = "";
        if(ans.second % 2 == 0){
            int temp = ans.second / 2;
            for(int i = ans.first - temp; i < ans.first + temp; i++)
                res += s[i];
        }
        else{
            int temp = ans.second / 2;
            for(int i = ans.first - temp; i <= ans.first + temp; i++)
                res += s[i];
        }
        return res;
    }
};
