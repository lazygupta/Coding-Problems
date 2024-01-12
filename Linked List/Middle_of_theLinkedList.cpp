// Using brute force method

// T.c = O(n) + O(n/2)
// s.c = O(1)

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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp;
        temp=head;
        int midnode=0,cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        midnode= (cnt/2)+1;
        temp=head;
        while(temp!=nullptr){
            midnode--;
            if(midnode==0){
                break;
            }
            temp=temp->next;
        }
        return temp;
    }
};


// Tortoise Hare method aka Slow and Fast pointers
// T.C = O(N/2);
//S.C = O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next != NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};
