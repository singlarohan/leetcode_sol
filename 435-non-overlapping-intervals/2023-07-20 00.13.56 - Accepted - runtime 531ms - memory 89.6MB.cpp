class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //take the smallest intervals?
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int last = INT_MIN;

        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] >= last){
                last = intervals[i][1];
                count++;
            }
            else if(intervals[i][1] < last){
                last = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};