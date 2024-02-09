// T.C = O(N & logN)
// S.C = O(N)

// Brute Force hashing method

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
    }
 };

int lengthOfLoop(Node *head) {
    // Write your code here
    map<Node*,int> mpp;
    int counter=0,timer=0;
    Node *temp=head;
    while(temp!=NULL){
        if(mpp.find(temp) != mpp.end()){
            return counter-mpp[temp];
        }
        mpp[temp]=timer++;
        counter++;
        temp=temp->next;
    }
    return 0;
}


// Tortoise and Hare Method
// Floyd Cycle Detection

// Time complexity: O(N), Only one traversal of the linked list is needed.
// Auxiliary Space: O(1), As no extra space is required.

int lengthOfLoop(Node *head) {
    // Write your code here
    Node *slow=head;
    Node *fast=head;
    int count=1;
    while (slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;

        if(slow == fast){
            int res = 1;
            Node* temp = slow;
            while (temp->next != slow) {
              res++;
              temp = temp->next;
            }
            return res;
        }
    }
    return 0;
}