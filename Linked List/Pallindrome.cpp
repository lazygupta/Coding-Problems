// Time Complexity: O(2 * N)
// Space Complexity: O(N)

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head;
        stack<int> s;
        while(temp!=NULL){
           s.push(temp->val);
           temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->val == s.top()){
                s.pop();
            }
            temp=temp->next;
        }
        return s.empty()?true:false;
    }
};