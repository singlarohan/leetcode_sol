class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto &x:asteroids){
            if(x > 0)
                st.push(x);
            else while(!st.empty() && abs(x) >= st.top()){
                if(abs(x) == st.top()){
                    st.pop();
                    break;
                }
                st.pop();
            }   
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};