// Go through the code properly
// See the dry run for why we have used third stacks

class MyQueue {
public:
    MyQueue() {
        
    }

    stack<int> st1;
    stack<int> st2;
    stack<int> st3;
    
    void push(int x) {
        st2.push(x);
        while(!st1.empty()){
            st3.push(st1.top());
            st1.pop();
        }
        while(!st3.empty()){
            st2.push(st3.top());
            st3.pop();
        }
        swap(st1,st2);
    }
    
    int pop() {
        int ans = st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

// Using two stacks

// First transfer everytime from s1 to s2 one by one
// Push the element in s1
// Transfer again from s2 to s1 one by one

stack<int> s1;
    stack<int> s2;
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }