// T.C = O(2*N)
// S.C = O(1)

// First calculate the length
// And then do basic operatyion to delete a node form a speicifc position

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
        if(!head) return head;
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count == n){
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }
        int index = count - n;
        temp = head;
        while(temp) {
            index--;
            if(index == 0) break;
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);
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