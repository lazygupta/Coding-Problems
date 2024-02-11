// T.C = O(N) + O(NlogN) + O(N)
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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head;
        auto it=v.begin();
        while(it!=v.end()){
            temp->val = *it;
            temp=temp->next;
            it++;
        }
        return head;
    }
};

// Doing it with MergeSort
// T.C = O (logN * (N +N/2)) // N logN for merge and O(N/2 ) for finding the middle node
// S.C = O(logN) // Recursive stack space

class Solution {
public:
    ListNode *findMiddle(ListNode* head){
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* list1Head, ListNode* list2Head) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode *temp=dummyNode;
        while(list1Head && list2Head){
            if(list1Head->val < list2Head->val){
                temp->next = list1Head;
                temp = list1Head;
                list1Head = list1Head->next;
            }
            else{
                temp->next = list2Head;
                temp = list2Head;
                list2Head = list2Head->next;
            }
        }
        if(list1Head) temp->next=list1Head;
        else temp->next=list2Head;
        return dummyNode->next;
    }

     ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middleNode = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middleNode->next;
        middleNode->next=NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeList(leftHead,rightHead);
    }
};