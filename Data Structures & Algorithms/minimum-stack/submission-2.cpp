class MinStack {

private:
    stack<int> s;
    stack<int> extra;

public:
    MinStack(){ }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            extra.push(val);
        }else{
            if(val<=extra.top()) 
                extra.push(val);
            s.push(val);
        }
    }

    void pop() {
        if(s.top() == extra.top())
            extra.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return extra.top();
    }
};
