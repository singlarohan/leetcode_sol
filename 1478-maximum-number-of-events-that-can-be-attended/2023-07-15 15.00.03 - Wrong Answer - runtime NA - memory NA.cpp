class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int last = 0;
        int ans = 0;
        for(auto &it:events){
            if(last < it[1]){
                last = max(last + 1, it[0]);
                ans++;
            }
        }
        return ans;
    }
};