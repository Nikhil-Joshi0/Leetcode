class MinStack {
public:

    stack<int> st1,st2;//main, helping

    MinStack() {
    }
    
    void push(int value) {
        st1.push(value);
        if(st2.empty() || st2.top() >= value)st2.push(value);
        return;
    }
    
    void pop() {
        if(st1.empty())return;
        else{
            int val = st1.top();
            st1.pop();
            if(st2.top() == val) st2.pop();
        }
        return;
    }
    
    int top() {
        int val = st1.top();
        return val;
    }
    
    int getMin() {
        if(st2.empty())return -1;
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */