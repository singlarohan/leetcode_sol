class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        long long ans{};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = costs.size();
        int l = 0, r = n - 1;
        // if((n + 1) / 2 < cand) pq.push();
        while(l < cand && l < n) pq.push({costs[l++], l - 1});
        l--;
        while(r > l && r >= n - cand) pq.push({costs[r--], r + 1});
        r++;
        if(cand >= (n + 1) / 2) l = INT_MAX;
        int count{};
        while(r > l && count != k){
            auto it = pq.top();
            pq.pop();
            ans += it.first;
            count++;
            if(it.second <= l) {
                pq.push({costs[++l], l});
            }
            else {
                pq.push({costs[--r], r});
            }
        }
        while(count != k){
            ans += pq.top().first;
            count++;
            pq.pop();
        }
        return ans;
    }
};