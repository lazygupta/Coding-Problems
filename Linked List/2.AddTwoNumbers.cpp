#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1;
        ListNode *t2=l2;
        ListNode *dummyNode=new ListNode(-1);
        ListNode *curr=dummyNode;
        int carry=0;
        while(t1 || t2){
            int sum=carry;
            if(t1) sum+= t1->val;
            if(t2) sum+= t2->val;
            ListNode *newNode = new ListNode(sum%10);
            carry = sum/10;
            curr->next = newNode;
            curr = curr->next;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(carry){
            ListNode *onenode=new ListNode(carry);
            curr->next=onenode;
        }
        return dummyNode->next;
    }
};