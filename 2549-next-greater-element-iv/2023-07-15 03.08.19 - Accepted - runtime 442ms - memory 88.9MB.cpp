class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        auto comp = [&](int a, int b){
            return nums[a] > nums[b];
        };
        vector<int> ans(nums.size(), -1);
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        priority_queue<int, vector<int>, decltype(comp)> pq2(comp);

        for(int i = 0; i < nums.size(); i++){
            while(!pq2.empty() && nums[pq2.top()] < nums[i]){
                ans[pq2.top()] = nums[i];
                pq2.pop();
            }
            while(!pq.empty() && nums[pq.top()] < nums[i]){
                pq2.push(pq.top());
                pq.pop();
            }
            pq.push(i);
        }
        return ans;
    }
};