class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string , int> mp;
        int ans{};
        bool flag{};
        for(int i = 0; i < words.size(); i++){
            if(mp[words[i]] == 0){
                if(words[i][0] != words[i][1]){
                    swap(words[i][0], words[i][1]);
                    mp[words[i]]++;
                }
                else if (!flag){
                    ans += 2, flag = true;
                }
            }
            else{
                ans += 4;
                mp[words[i]]--;
            }
        }
        return ans;
    }
};