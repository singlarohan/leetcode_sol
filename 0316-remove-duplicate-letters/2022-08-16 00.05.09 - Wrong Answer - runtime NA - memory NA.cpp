class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        sort(s.begin(), s.end(), greater<>());
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i<s.size(); i++){
            if(st.top() != s[i])
            st.push(s[i]);
        }
        s = "";
        while(!st.empty())
            s.push_back(st.top()), st.pop();
        return s;
    }
};