// Time Complexity: O(2 * N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head;
        stack<int> s;
        while(temp!=NULL){
           s.push(temp->val);
           temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->val == s.top()){
                s.pop();
            }
            temp=temp->next;
        }
        return s.empty()?true:false;
    }
};

// Without any Space COmplexity
// Using Tortise and Hare method

// Time Complexity: O (2*N) 
// Space Complexity: O(1)

class Solution {
public:
    ListNode* Reverse(ListNode *head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode *front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head==nullptr && head->next==nullptr){
            return true;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reversed_List = Reverse(slow->next);
        ListNode* first=head;
        ListNode* second=reversed_List;

        while(second!=nullptr){
            if(first->val != second->val ) {
                Reverse(reversed_List);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        Reverse(reversed_List);

        return true;
    }
};