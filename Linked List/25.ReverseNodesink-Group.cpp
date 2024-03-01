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

class Solution
{
public:
    ListNode *getkthNode(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != NULL && k > 0)
        {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *front;
        ListNode *temp = head;
        while (temp)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // if(head==nullptr){
        //     return head;
        // }
        ListNode *temp = head;
        ListNode *prevNode = nullptr;
        while (temp)
        {
            ListNode *kthNode = getkthNode(temp, k);
            if (kthNode == NULL)
            {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseList(temp);
            if (temp == head)
            {
                head = kthNode;
            }
            else
            {
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};