// T.C = O (n+m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mpp;
        ListNode* l1=headA;
        ListNode* l2=headB;
        while(l1){
            mpp[l1]++;
            l1 = l1->next;
        }
        while(l2){
            if(mpp.find(l2) != mpp.end()){
                return l2;
            }
            l2=l2->next;
        }
        return nullptr;
    }
};


// T.C = O(n + 2n)
// S.C = O(1)

class Solution {
public:

    ListNode* CollisionPoint(ListNode *t1,ListNode *t2,int d){
        while(d){
            d--;
            t2=t2->next;
        }
       while(t1 != NULL) {
            if(t1 == t2) return t1;
            t2 = t2->next;
            t1 = t1->next;
        }
        return t1;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA;
        ListNode* t2=headB;
        int n1=0,n2=0;
        while(t1){
            n1++;
            t1=t1->next;
        }
        while(t2){
            n2++;
            t2=t2->next;
        }
        int d =n1-n2;
        if(d<0)
            return CollisionPoint(headA,headB,abs(d));
        else
            return CollisionPoint(headB,headA,d);
    }
};