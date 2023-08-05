class Solution {
public:
    void print_stack(stack<int> s){
        while(!s.empty()) {
            cout<<s.top();
            s.pop();
        }
    }

    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size(), ans = 0;
        int curr {};
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                if(s[i] == '('){
                    curr = 0;
                }
                else st.push(curr);
            }
            else{
                if(s[i] == '('){
                    int t = st.top();
                    cout<<t<<endl;
                    st.pop();
                    ans = max(ans, t + 2);
                    if(!st.empty()) st.top() = t + 2;
                    curr += 2;
                }
                else st.push(st.top());
            }
            print_stack(st);
            cout<<endl;
        }
        return ans;
    }
};