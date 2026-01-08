class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;      // Copy next node's value
        node->next = node->next->next;    // Skip next node
    }
};
