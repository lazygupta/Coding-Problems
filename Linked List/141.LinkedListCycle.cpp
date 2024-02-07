// Using HAshing

// T.C = O(N*(2*logn))
// S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> mpp;
        ListNode *temp=head;
        while(temp!=NULL){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            mpp[temp]++;
            temp=temp->next;
        }
        return false;
    }
};

// Using tortoise and hare method
// Slow and fast pointer approach

// T.C = O(N)
// S.C = O(1)

 struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next != NULL){
            slow=slow->next;
            fast = fast->next->next;
            if(fast <= slow && fast >= head){
                return true;
            }
        }
        return false;
    }
};




