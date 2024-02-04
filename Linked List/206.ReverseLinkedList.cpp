// Brute force method include stack implementation for storing values

// T.C = O(2N)
// S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp=head;
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};

// In place 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *temp=head;
        while(temp!=NULL){
            ListNode *front = temp->next;

            temp->next=prev;
            prev=temp;

            temp=front;
        }

        return prev;
    }
};

// Using Recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *newHead = reverseList(head->next);

        ListNode *front=head->next;
        front->next=head;
        head->next =NULL;

        return newHead;
    }
};