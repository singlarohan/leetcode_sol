class MinStack {
public:
    stack<long long> st;
    long long M = INT_MAX + 1LL;
    MinStack() {
        
    }
    
    void push(int val) {
        int curr = st.empty() ? val : getMin();

        st.push(val * M + min(val, curr));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top() / M;
    }
    
    int getMin() {
        return st.top() % M;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */