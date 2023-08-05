class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string , int> mp;
        int ans{};
        bool flag{};
        for(int i = 0; i < words.size(); i++){
            if(mp[words[i]] == 0){
                swap(words[i][0], words[i][1]);
                mp[words[i]]++;
            }
            else{
                ans += 4;
                mp[words[i]]--;
            }
        }
        for(auto it: mp){
            if(it.second == 1 && it.first[0] == it.first[1]){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};