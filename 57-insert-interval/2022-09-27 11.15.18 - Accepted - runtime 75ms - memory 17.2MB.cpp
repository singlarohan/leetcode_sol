class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        // int l{INT_MAX}, r{INT_MIN};
        // for(int i = 0; i<intervals.size(); i++){
        //     if(l == INT_MAX && intervals[i][0] >= newInterval)
        // }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<int> temp;
        // vector<vector<int>> ans;
        temp = intervals[0];
        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i][0] <= temp[1])
                temp[1] = max(intervals[i][1], temp[1]);
            else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        ans.push_back(temp);
        return ans;
        return ans;
    }
};