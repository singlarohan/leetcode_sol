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
        while(r != l && k--){
            auto it = pq.top();
            pq.pop();
            ans += it.first;
            if(it.second > l) pq.push({costs[++l], l});
            else pq.push({costs[--r], r});
        }
        while(k--){
            ans += pq.top().first;
            pq.pop();
        }
        return ans;
        // while(k-- && l < r - 1){

        // }
    }
};