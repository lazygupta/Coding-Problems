class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(),nums.end());
        ListNode node(0,head);
        ListNode* current = &node;
        while(current->next != nullptr){
            if(st.find(current->next->val) != st.end()){
                current->next = current->next->next;
            }else{
                current = current->next;
            }
        }
        return node.next;
    }
};