// Hashing
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

// using Tortoise and Hare method

// S.C = O(N)

// See the concept here = https://i.ibb.co/MMDpL1R/Screenshot-2024-02-07-211221.png

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next != NULL){
            // Finding Collission point 
            slow = slow->next;// Slow ko ek step se le jaao
            fast = fast->next->next; // Fast ko do step se le jaao

            if(slow==fast){// Collission Area
                slow=head;// Slow ko fir se suruat me rakh do
                while(slow!=fast){ // Aur fir se slow ko bolo fast ke paas jaaye ek ek step se
                    slow=slow->next;// Slow ek step se jayega
                    fast=fast->next;// fast bhi ab ek hi step se jayega
                }
                return fast;
                // And nwhy this works?
                // The answer is that fast is moving by 2 times the slow is moving so eventually
                // If slow moves 1 distance fast moves two distance towards him
                // A moment will come the fast and slow will be on the same point, So they will collide
                // And what is the reason behind moving slow and fast one step at the moment it collides
            }
        }
        return NULL;
    }
};
