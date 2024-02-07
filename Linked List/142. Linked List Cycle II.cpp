


#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mpp;
        ListNode *temp = head;
        while( temp != nullptr && temp->next != nullptr){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp[temp]++;
            temp=temp->next;
        }
        return NULL;
    }
};