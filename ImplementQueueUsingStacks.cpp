class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()) {
            int t = output.top();
            output.pop();
            return t;
        } else {
            //move all elements from input to output and pop
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int t = output.top();
            output.pop();
            return t;
        }
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        } else {
            //move all elements from input to output
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        if(output.empty() && input.empty())
            return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
