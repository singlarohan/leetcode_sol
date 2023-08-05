class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        auto comp = [&](int a, int b){
            return nums[a] > nums[b];
        };
        vector<int> ans(nums.size(), -1);
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        stack<int> st;

        for(int i = 0; i < nums.size(); i++){
            while(!pq.empty() && nums[pq.top()] < nums[i]){
                ans[pq.top()] = nums[i];
                pq.pop();
            }
            while(!st.empty() && nums[i] > st.top()){
                pq.push(st.top());
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};