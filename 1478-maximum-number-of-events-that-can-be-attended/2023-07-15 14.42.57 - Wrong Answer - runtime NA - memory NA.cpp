class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end());

        int i = 0, ans = 0;
        while(i < n - 1){
            while(i + 1 < n && events[i][1] < events[i++][0]) i++;
            ans++;
        }
        return ans + 1;
    }
};