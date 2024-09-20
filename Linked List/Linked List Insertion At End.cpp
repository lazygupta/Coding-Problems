class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node *temp = new Node(x);
        if (head == NULL) {
            return temp;
        }
        Node *newNode = head;
        while (newNode->next != NULL) {
            newNode = newNode->next;
        }
        
        newNode->next = temp;
        return head;
    }
};