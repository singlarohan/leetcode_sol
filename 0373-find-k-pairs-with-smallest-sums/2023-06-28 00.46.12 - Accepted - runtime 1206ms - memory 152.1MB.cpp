class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& num1, vector<int>& num2, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                int curr = num1[i] + num2[j];
                if(pq.size() >= k && pq.top().first < curr) break;
                pq.push({curr, {num1[i], num2[j]}});
                if(pq.size() > k) pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};