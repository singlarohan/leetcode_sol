class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b){
            return capital[a] < capital[b];
        });

        priority_queue<int> pq;

        int i = 0;
        while(k--){
            while(i < n && capital[idx[i]] <= w)
                pq.push(profits[idx[i++]]);
            
            if(pq.empty()) break;

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};