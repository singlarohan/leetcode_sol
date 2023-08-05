class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && s[i] == st.top() + 'a'){
                st.top() += 1;
                if(st.top() == 3)
                st.pop();
            }
            else if(s[i] == 'a') st.push(1);
            else return false;
        }
        return st.empty();
    }
};