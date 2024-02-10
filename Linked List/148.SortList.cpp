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