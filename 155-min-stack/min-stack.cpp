class MinStack {
public:
    std::vector<int> stack; 
    std::vector<int> minStack; 
    MinStack() {
        stack = {}; 
        minStack = {}; 
    }
    
    void push(int val) {
        stack.push_back(val); 
        if(!(minStack.empty()))
        {
            if(minStack.back() >= val) minStack.push_back(val); 
        }else
        {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        int val {stack.back()}; 
        stack.pop_back(); 

        if(val == minStack.back())
        {
            minStack.pop_back(); 
        }
    }
    
    int top() {
        return stack.back(); 
    }
    
    int getMin() {
        return minStack.back(); 
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