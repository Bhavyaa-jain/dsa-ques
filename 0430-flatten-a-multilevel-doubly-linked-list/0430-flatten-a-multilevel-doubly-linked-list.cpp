/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


class Solution {
public:
    Node* flatten(Node* head) {

        if (head == NULL)
            return head;

        Node* curr = head;

        while (curr != NULL) {

            if (curr->child != NULL) {

                Node* nextNode = curr->next;

                Node* childNode = flatten(curr->child);

                curr->next = childNode;
                childNode->prev = curr;

                curr->child = NULL;

                Node* temp = childNode;

                while (temp->next != NULL) {
                    temp = temp->next;
                }

                temp->next = nextNode;

                if (nextNode != NULL) {
                    nextNode->prev = temp;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};
