class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //maxheap
        priority_queue<int> pq;
        for(auto x:stones) pq.push(x);
        while(pq.size() >= 2){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            a == b ? a = 0: a = abs(a - b);
            if(a) pq.push(a);
        }
        return pq.empty() ? 0 : pq.top();
    }
};