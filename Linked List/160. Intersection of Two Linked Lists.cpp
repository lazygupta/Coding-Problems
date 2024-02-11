// T.C = O ( N) + O(N)
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