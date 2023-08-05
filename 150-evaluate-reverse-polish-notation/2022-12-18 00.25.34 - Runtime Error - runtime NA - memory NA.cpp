class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int temp = st.top();
                st.pop();
                st.top() += temp;
            }
            else if(tokens[i] == "-"){
                int temp = st.top();
                st.pop();
                st.top() -= temp;
            }            
            else if(tokens[i] == "*"){
                int temp = st.top();
                st.pop();
                st.top() *= temp;
            }            
            else if(tokens[i] == "/"){
                int temp = st.top();
                st.pop();
                st.top() /= temp;
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};