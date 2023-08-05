class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i = 0;
        while(i < asteroids.size() && asteroids[i] < 0) 
            st.push(asteroids[i++]);
        for(i; i < asteroids.size(); i++){
            int x = asteroids[i];
            if(x > 0)
                st.push(x);
            else while(!st.empty() && st.top() > 0 && abs(x) >= st.top()){
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