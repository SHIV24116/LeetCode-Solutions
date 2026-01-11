class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        k = k % n;
        if (k == 0) return head;

        // Make list circular
        tail->next = head;

        int steps = n - k;
        ListNode* newTail = tail;
        while (steps--) {
            newTail = newTail->next;
        }

        // Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
