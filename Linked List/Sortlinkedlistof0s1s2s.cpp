// T.C = O (N)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* sortList(Node *head){
    Node* zeroesHead=new Node(-1);
    Node* onesHead=new Node(-1);
    Node* twosHead=new Node(-1);
    Node *zero=zeroesHead;
    Node *one=onesHead;
    Node *two=twosHead;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data ==1){
            one->next = temp;
            one =temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp= temp->next;
    }
    zero->next = (onesHead->next)?onesHead->next:twosHead->next;
    one->next = (twosHead->next);
    two->next = nullptr;
    Node* newHead=zeroesHead->next;
    delete(zeroesHead);
    return newHead;
}