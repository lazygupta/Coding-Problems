// Stack is LIFO

// Queue is FIFO


// Stack has top variable to check for the index


// Queue has front and rear

// To push in Stack
void MyStack :: push(int x)
{
    // Your Code
    if(top==n-1) return;
    top++;
    arr[top]=x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1) return -1;
    int ans = arr[top];
    top--;
    return ans;    
}

//-------------------------//

void MyQueue :: push(int x)
{
    if(rear==100005-1) return;
    arr[rear] = x;
    rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(rear==front) return -1;
    int ans = arr[front];
    front++;
    return ans;  
}