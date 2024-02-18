// T.C = O(N) + O(N) + O(N)
// S.C = O(1)


#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
     int data;
     Node *next;
     Node() {
             this->data = 0;
         this->next = NULL;
     }
     Node(int data) {
             this->data = data;
         this->next = NULL;
     }
     Node (int data, Node *next) {
             this->data = data;
         this->next = next;
     }
};

Node *reverse(Node *head){
    Node *temp=head;
    Node *prev=NULL;
    while(temp){
        Node *front= temp->next;
        temp->next=prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
    head = reverse(head);
    Node *temp=head;
    int carry = 1;
    while(temp){
        temp->data = temp->data + carry;
        if(temp->data <= 9){
            carry=0;
            break;
        }
        else{
            temp->data =0;
            carry =1;
        }
        temp = temp->next;
    }
    if(carry == 1) {
        Node * newNode = new Node(1);
        head = reverse(head);
        newNode->next=head;
        return newNode;
    }
    head = reverse(head);
    return head;
}

// Using Recursion for backtracking


int helper(Node *head){
    if(head==NULL){
        return 1;
    }  
    int carry = helper(head->next);
    head->data = head->data + carry;
    if(head->data <=9){
        return 0;
    }
    else{
        head->data = 0;
        return 1;
    }
}

Node *addOne(Node *head)
{
    int carry = helper(head);
    if(carry==1){
        Node * newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}