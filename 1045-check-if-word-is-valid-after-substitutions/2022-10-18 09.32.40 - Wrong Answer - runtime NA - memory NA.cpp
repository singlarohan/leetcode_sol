class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && s[i] == st.top() + 'a'){
                st.pop();
                st.push(s[i] - 'a' + 1);
                if(st.top() == 3)
                st.pop();
            }
            else
                st.push(1);
        }
        return st.empty();
    }
};