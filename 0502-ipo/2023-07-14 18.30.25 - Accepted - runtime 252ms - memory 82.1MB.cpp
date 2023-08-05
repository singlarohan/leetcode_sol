class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> res;
        for(int i = 0; i < n; i++) res.push_back({profits[i], capital[i]});

        sort(res.begin(), res.end(), [&](pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second;
        });
        priority_queue<int> pq;
        int i = 0, count = 0;
        while(count < k){
            while(i < n && res[i].second <= w)
                pq.push(res[i++].first);

            if(i >= n || pq.empty()) break;

            if(!pq.empty() && w < res[i].second) {
                w += pq.top();
                count++;
                pq.pop();
            }
        }
        while(!pq.empty() && count < k){
            w += pq.top();
            count++;
            pq.pop();
        }
        return w;
    }
};