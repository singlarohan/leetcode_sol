class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        // for(auto &x:piles) pq.push(x);
        while(k--){
            int temp = pq.top();
            pq.pop();
            temp -= temp/2;
            pq.push(temp);
        }
        int ans{};
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};