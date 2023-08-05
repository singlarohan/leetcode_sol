class Solution {
private:
    int n;
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sorting widths in ascending and heights in descending
        //to reduce it to a simple LIS problem of heights
        // (since width will only increase moving forward and for the
        // same width no heights will be descending so LIS for height will work)
        //but how dp? dp -> n^2 noi?

        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        n = envelopes.size();
        
        //USING BINARY SEARCH
        //if we have
        //[5,4],[6,4],[6,7],[2,3]
        //it becomes
        //[2,3] [5,4] [6,7] [6,4]
        // we can do binary search LIS on the 2nd counterpart (height)

        vector<int> heights;
        for(int i = 0; i < n; i++){
            int temp = envelopes[i][1];
            if(heights.empty() || heights.back() < temp) heights.push_back(temp);

            else *lower_bound(heights.begin(), heights.end(), temp) = temp;
        }
        return heights.size();
    }
};