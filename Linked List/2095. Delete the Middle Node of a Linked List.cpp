// T.C = O(N)
// S.C = O(1)

// Tortoise and Hare method

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head->next == nullptr){
            return NULL;
        }
        fast=fast->next->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next=slow->next->next;
        delete(temp);
        return head;
    }
};