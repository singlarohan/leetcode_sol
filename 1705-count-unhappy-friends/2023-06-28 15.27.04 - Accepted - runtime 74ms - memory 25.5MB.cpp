class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<vector<int>> rank (n, vector<int>(n)); //lower value in this == higher pref
        for(int i = 0; i < pref.size(); i++)
            for(int j = 0; j < pref[i].size(); j++)
                rank[i][pref[i][j]] = j;
        
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
                int ene = paired[pref[i][j]];

                if(rank[pref[i][j]][ene] > rank[pref[i][j]][i]){
                    unhappy++;
                    break;
                }
                j++;
            }
        }
        return unhappy;
    }
};