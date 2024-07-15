// Just basic linked list questions


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == nullptr){
            return {-1,-1};
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        int criticalPoints = 0;
        int minDistance = INT_MAX;
        vector<int> l;
        int index = 1;
        while(curr->next!=nullptr && curr!=nullptr){
            if(prev!=nullptr){
                if( (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val) ){
                criticalPoints++;
                l.push_back(index);
                }
            }
            index++;
            prev = curr;
            curr = curr->next;
        }
        if(criticalPoints < 2) return {-1,-1};
        for (int i = 1; i <l.size(); i++) {
            minDistance = min(minDistance,l[i]-l[i-1]);
        }
        int maxDistance = l[l.size()-1]-l[0];
        return {minDistance,maxDistance};
    }
};