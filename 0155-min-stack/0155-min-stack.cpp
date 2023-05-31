class MinStack {
public:
    stack<int> s;
    int mn;
    MinStack() {
        mn = INT_MAX;
    }
    
    void push(int val) {
        if(val <= mn){
            s.push(mn);
            mn = val;
        }
        s.push(val);
    }
    
    void pop() {
        if(s.top() == mn){
            s.pop();
            mn = s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn;
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