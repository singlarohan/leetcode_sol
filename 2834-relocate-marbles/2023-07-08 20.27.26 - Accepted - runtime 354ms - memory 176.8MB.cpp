class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& From, vector<int>& To) {
        unordered_set<int> st;
        for(auto x:nums) st.insert(x);
        for(int i = 0; i < From.size(); i++){
            int x = From[i];
            int y = To[i];
            if(st.find(x) != st.end()){
                st.erase(x);
                st.insert(y);
            }
        }
        vector<int> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};