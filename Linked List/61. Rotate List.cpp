// Time Complexity: O(n*k) + O(n)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
        ListNode *temp = head;
        int count=0;
        while(temp){
            temp=temp->next;
            count++;
        }
        k=k%count;
        temp =head;
        for(int i=0;i<k;i++){
            ListNode *temp=head;
            while(temp->next->next) temp = temp->next;
            ListNode *end = temp->next;
            temp->next = nullptr;
            end->next = head;
            head = end;
        }
        return head;
    }
};

// Optimal Solution

// Making it a circular linked list
// After getting the length of the linked list
// We break the list fron (length-k)th node

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
        ListNode *temp = head;
        int count=1;
        while(temp->next){
            temp=temp->next;
            ++count;
        }
        temp->next=head;
        k=k%count;
        int length = count-k;
        while(length--){
            temp=temp->next;
        }
        head = temp->next;
        temp->next=nullptr;
        return head;
    }
};