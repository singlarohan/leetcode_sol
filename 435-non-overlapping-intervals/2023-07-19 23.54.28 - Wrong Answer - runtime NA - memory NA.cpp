class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //take the smallest intervals?
        sort(intervals.begin(), intervals.end());
        map<int, int> mp;
        int maxi = 1;
        for(int i = 0; i < intervals.size(); i++){
            // cout<<intervals[i][0]<<endl;
            if(mp.empty())
                mp[intervals[i][1]] = 1;

            else{
                auto it = mp.upper_bound(intervals[i][0]);

                if(it == mp.begin()) mp[intervals[i][1]] = 1;

                else{
                    it--;
                    mp[intervals[i][1]] = 1 + (it) -> second;
                    maxi = max(maxi, 1 + it -> second);
                }
            }
        }
        return intervals.size() - maxi;   
    }
};