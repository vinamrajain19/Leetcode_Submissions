class MinStack {
public:
    stack<int> s;
    int mini = INT_MAX;
    
    void push(int val) {
        if (val <= mini) //we'll push previous min value into the stack before pushing new min val, coz when we'll pop eg. min element then we need to update mini with prev min value   
        {
            s.push(mini); //we'll use it to update mini when popping min element!
            mini = val; //update mini with min val
        }
        s.push(val);
    }
    
    void pop() {
        if (s.top() == mini) //this means mini got updated here, and we know that we have stored previous min value in stack before pushing new minimum!
        {
            s.pop(); //popping curr min value 
            mini = s.top(); //this is our previous min value, we'll update mini, and now we'll pop it as well!
        }
        s.pop();
    }
    
    int top() {return s.top(); } 
    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */