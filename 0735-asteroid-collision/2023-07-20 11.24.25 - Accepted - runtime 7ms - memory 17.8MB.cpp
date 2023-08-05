class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto &x : asteroids){
            if(x > 0)
                st.push(x);
            else {
                bool flag{true};
                while(flag && !st.empty() && st.top() > 0 && abs(x) >= st.top()){
                    flag = !(abs(x) == st.top());

                    st.pop();
                }
                if((st.empty() || st.top() < 0) && flag) st.push(x);
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