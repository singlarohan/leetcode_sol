class Solution {
private:
    int n;
public:
    int minOperations(vector<int>& nums) {
        n = nums.size();
        unordered_set<int> st;
        for(auto &x:nums) {
            if(st.find(x) != st.end()) x = INT_MAX;
            st.insert(x);
        }
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        for(auto x:nums){
            if(x == INT_MAX) break;
            
            int count = 0;
            for(int j = 1; j < nums.size(); j++)
                if(st.find(x + j) == st.end()) count++;
            
            ans = min(count, ans);
        }
        return ans;
    }
};