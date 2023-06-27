class MyStack {
private: 
    queue<int> q1;
    queue<int> q2;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
            // copy elements of q1 to q2
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            
            // again copy element from q2 to q1
            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        
        return;
        
    }
    
    int pop() {
        if(q1.empty()) return NULL;
        
        int ans = q1.front();
        q1.pop();
        
        return ans;
    }
    
    int top() {
        if(q1.empty()) return NULL;
        
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */