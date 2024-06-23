// Basically , you have to take help of two queues
// You will push the element in q2 first
// then transfer the element of q1 to q2 one by one till q1 is empty(Note: you hav to transfer from q1 to q2 means you have to pop up from q1)
// Then swap q1 and q2

// how this works?
// The q1 will everytime will have the element in the style fo stack
// Means the q1.front() will be acting as st.top()


// using two queues
    queue<int> q1;
    queue<int> q2;
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        int ans = q1.front();
        return ans;
    }
    
    bool empty() {
        return q1.empty();
    }


// Using single queue

// Act like q1 is within q2
// And repeat the process of the two queues rule

class MyStack {
public:
// using one queue
    MyStack() {
        
    }
    queue<int> q;
    
    void push(int x) {
        q.push(x);
        for(int i=1;i<q.size();i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int ans = q.front();
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};