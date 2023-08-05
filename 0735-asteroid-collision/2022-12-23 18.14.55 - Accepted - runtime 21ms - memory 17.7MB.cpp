class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto &x : asteroids){
            if(x > 0)
                st.push(x);
            else {
                bool flag{true};
                while(!st.empty() && st.top() > 0 && abs(x) >= st.top()){
                    if(abs(x) == st.top()){
                        st.pop();
                        flag = false;
                        break;
                    }
                    st.pop();
                }
                if((st.empty() || st.top() < 0) && flag)st.push(x);
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