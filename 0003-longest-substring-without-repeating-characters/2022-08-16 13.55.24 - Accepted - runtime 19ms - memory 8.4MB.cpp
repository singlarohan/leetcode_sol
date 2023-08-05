class Solution {
public:
    //FOR LONGEST SUBSEQUENCE :')
    // int solve(int i, string s, vector<char> &temp, unordered_map<char, int> &mp){
    //     if(i >= s.size())
    //         return temp.size();
    //     mp[s[i]]++;
    //     if(mp[s[i]] > 1){
    //         mp[s[i]]--;            
    //         return INT_MIN;
    //     }
    //     temp.push_back(s[i]);
    //     int l = solve(i+1, s, temp, mp);
    //     mp[s[i]]--;
    //     temp.pop_back();
    //     int r = solve(i+1, s, temp, mp);
    //     return max(l,r);
    // }
    int lengthOfLongestSubstring(string s) {
        // int ans{1};
        unordered_map<char, int> mp;
        // vector<char> temp;
        // return solve(0, s, temp, mp);
        int ans{}, begin{};
        for(int i = 0; i< s.size(); i++){
            if(mp[s[i]] != 0){
                while(mp[s[i]] != 0){
                    mp[s[begin]] = 0;
                    begin++;
                }
            }
            mp[s[i]]++;
            ans = max(ans, 1 + i - begin);
        }
        return ans;
    }
};