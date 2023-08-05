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
        // while(!pq.empty()) {
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        // cout<<l << " "<<r<<endl;
        if(cand >= (n + 1) / 2) l = 1e9;
        for(int i = 0; i < k; i++){
            auto it = pq.top();
            // pq.pop();
            // cout<<it.first<<" "<<it.second<<endl;
            ans += it.first;
            if(r <= l + 1) continue;
            if(it.second <= l) pq.push({costs[++l], l});
            else pq.push({costs[--r], r});
        }
        return ans;
    }
};