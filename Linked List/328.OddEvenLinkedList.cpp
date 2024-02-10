// T.C = O(N/2 + N/2 + N)
// S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        queue<int> qu;
        ListNode *temp=head;
        if(temp == nullptr || temp->next ==nullptr) return head;
        while(temp!=nullptr && temp->next){
            qu.push(temp->val);
            temp=temp->next->next;
        }
        if(temp) qu.push(temp->val);
        temp=head->next;
        while(temp!=NULL && temp->next!=NULL){
            qu.push(temp->val);
            temp=temp->next->next;
        }
        if(temp) qu.push(temp->val);
        temp=head;
        while(temp!=NULL){
            temp->val=qu.front();
            qu.pop();
            temp=temp->next;
        }
        return head;
    }
};

// Without space complexity
// Time Complexity: O (2*N) 
// Space Complexity: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == nullptr){
            return head;
        }
        ListNode *odd= head;
        ListNode *even= head->next;
        ListNode *evenhead=head->next;
        while(odd->next!=NULL && even->next!=nullptr){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};