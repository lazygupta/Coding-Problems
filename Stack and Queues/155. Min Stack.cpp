// Store the minimum element eveyrtime in the pair upto that element

// If we insert 1 , then min = 1
// insert -2 , min =-2
// insert 3 , min =-2
// insert -5, min = -5

// So if -5 pops out then we get the secondminimum guy that is -2

class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>> st;
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val,min(st.top().second,val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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