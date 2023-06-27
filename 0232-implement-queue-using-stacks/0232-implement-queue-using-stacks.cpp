class MyQueue {
private: 
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // keeping pushing values to st2
        st2.push(x); 
    }
    
    int pop() {
        if(st2.empty()) {
            return NULL;
        }
        
        // copy elements of st2 tp st1
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        
        int ans = st1.top();
        st1.pop();
        
        // copy elements back to st2 from st1
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        return ans;
    }
    
    int peek() {
        if(st2.empty()) return NULL;
        
        
        // copy elements of st2 tp st1
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        
        int ans = st1.top();
        
        // copy elements back to st2 from st1
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        return ans;
    }
    
    bool empty() {
        return st2.empty();
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