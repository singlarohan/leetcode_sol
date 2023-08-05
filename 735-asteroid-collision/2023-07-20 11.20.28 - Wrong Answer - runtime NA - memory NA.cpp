class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto x:asteroids){
            if(x < 0){
                while(!st.empty() && st.top() > 0 && abs(x) > st.top())
                    st.pop();
                if(st.empty()) st.push(x);
                
                while(!st.empty() && st.top() == abs(x)) st.pop();
            }
            else st.push(x);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};