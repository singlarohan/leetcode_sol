class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](vector<int> &a, vector<int> &b){
            return pow(a[0], 2) + pow(a[1],2) > pow(b[0], 2) + pow(b[1],2);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        for(int i = 0; i < points.size(); i++)
            pq.push(points[i]);
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};