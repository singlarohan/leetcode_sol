class MinStack {
private:
        vector<pair<int,int>> arr;
        int mini{INT_MAX};
public:
    MinStack() {

    }
    
    void push(int val) {
        arr.push_back({val, mini});
        mini = min(val, mini);
    }
    
    void pop() {
        if(arr.back().first == mini)
            mini = arr.back().second;
        arr.pop_back();
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return mini;
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