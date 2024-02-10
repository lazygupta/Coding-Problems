// T.C = O(2*N)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n){
            ListNode* newHead= head->next;
            delete(head);
            return newHead;
        }
        int res=cnt-n;
        temp=head;
        while(temp!=NULL){
            res--;
            if(res==0) break;
            temp=temp->next;
        }
        ListNode* newNode= temp->next;
        temp->next=temp->next->next;
        delete(newNode);
        return head;
    }
};

// Somewhat less complexity

// T.C = O(N)
// S.C = O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        ListNode* slow= head;
        ListNode* fast=head;
        int cnt=n;
        while(cnt!=0){
            fast=fast->next;
            cnt--;
        }
        if(fast==nullptr) return head->next;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* newNode= slow->next;
        slow->next=slow->next->next;
        delete(newNode);
        return head;
    }
};