class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interv) {
        vector<vector<int>> ans;
        sort(interv.begin(), interv.end());
        vector<int> tp(2);
        tp[0] = interv[0][0], tp[1] = interv[0][1];
        for(int i = 1; i < interv.size(); i++){
            if(tp[1] >= interv[i][0])
                tp[1] = max(tp[1], interv[i][1]);
            else{
                ans.push_back(tp);
                tp[0] = interv[i][0];
                tp[1]  = interv[i][1];
            }
        }
        ans.push_back(tp);
        return ans;
    }
};