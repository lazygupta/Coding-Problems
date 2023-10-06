#include<bits/stdc++.h>
using namespace std;


// Creating a linked list from an array

class Node {
 public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* ptr = head;
     for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        ptr->next=newNode;
        ptr= ptr->next; 
    }
    return head;
}

// Inserting a node

Node* insertAtFirst(Node* list, int newValue) {
    Node *newnode = new Node(newValue , list);
    list=newnode;
    return list;
}

// Deleting a node

class Solution {
public:
    void deleteNode(Node* node) {
        node->data =node->next->data;
        node->next=node->next->next; 
    }
};