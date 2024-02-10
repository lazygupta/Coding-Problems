


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