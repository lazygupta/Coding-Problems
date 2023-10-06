
class Node
{
public:
int data;
Node *next, *prev;
Node() : data(0), next(nullptr), prev(nullptr) {}
Node(int x) : data(x), next(nullptr), prev(nullptr) {}
Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}

};


// Array into doubly linked list

#include<bits/stdc++.h>
using namespace std;

Node *constructDLL(vector<int> &arr) {
    Node* newNode = new Node(arr[0],NULL,NULL);
    Node* head=newNode;

    
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node *newNode=new Node(arr[i]);
        temp->next=newNode;
        newNode->prev=temp;
        temp=temp->next;
    }
    return head;
}

// Insert a node at the end of tail

Node * insertAtTail(Node *head, int k) {

    Node* newNode = new Node(k,nullptr,nullptr);
    if(head==nullptr) head=newNode;
    Node* temp = head;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
    return head;
}