class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<int> paired(n);
        for(int i = 0; i < pairs.size(); i++){
            paired[pairs[i][0]] = pairs[i][1];
            paired[pairs[i][1]] = pairs[i][0];
        }
        int unhappy{};
        for(int i = 0; i < n; i++){
            int p = paired[i];
            int j = 0;
            while(pref[i][j] != p){
                // pair[pref[i][j]];
                bool flag {};
                for(int k = 0; k < n - 1; k++){
                    if(pref[pref[i][j]][k] == paired[pref[i][j]]) break;
                    if(pref[pref[i][j]][k] == i) {
                        flag = true;
                        break;
                    }
                }
                j++;
                if(flag) {
                    unhappy++; 
                    break;
                }
            }
        }
        return unhappy;
    }
};