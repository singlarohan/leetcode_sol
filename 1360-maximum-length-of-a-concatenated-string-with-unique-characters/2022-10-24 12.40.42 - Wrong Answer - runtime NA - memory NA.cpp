class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bool> mp(26, false);
        int ans{0};
        auto solve = [&](int i, int curr, auto &&self){
            if(i == arr.size()){
                ans = max(curr, ans);
                return;
            }
            vector<bool> temp = mp;
            for(int j = 0; j < arr[i].size(); j++){
                if(mp[arr[i][j] - 'a']){
                    ans = max(ans, curr);
                    mp = temp;
                    return;
                }
                mp[arr[i][j] - 'a'] = true;
            }
            self(i + 1, curr + arr[i].size(), self);
            mp = temp;
            self(i + 1, curr, self);
            return;
        };
        solve(0, 0, solve);
        return ans;
    }
};