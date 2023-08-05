class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //take the smallest intervals?
        sort(intervals.begin(), intervals.end());
        map<int, int> mp;
        int maxi = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(mp.lower_bound(intervals[i][0]) == mp.end())
                mp[intervals[i][1]] = 1;
            else{
                if((mp.lower_bound(intervals[i][0])) -> first == intervals[i][1]) continue;
                mp[intervals[i][1]] = 1 + (mp.lower_bound(intervals[i][0])) -> second;
            }
            maxi = max(maxi, mp[intervals[i][1]]);
        }
        return intervals.size() - maxi;   
    }
};