class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //using O(n)
        int i{}, j{};
        stack<int> st;
        while(i < pushed.size()){
            if(pushed[i] == popped[j]) j++;
            else if(!st.empty() && st.top() == popped[j]) {
                st.pop(), j++;
                st.push(pushed[i]);
            }
            else st.push(pushed[i]);
            i++;
        }
        while(!st.empty() && st.top() == popped[j++])
            st.pop();
        return st.empty();
    }
};