class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* ans = new ListNode(0);
        ans->next = head;

        ListNode* start = ans;
        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (true) {
            // check if k nodes exist
            ListNode* check = temp;
            for (int i = 0; i < k; i++) {
                if (!check) return ans->next;
                check = check->next;
            }

            // reverse k nodes
            prev = check;
            ListNode* cur = temp;

            for (int i = 0; i < k; i++) {
                ListNode* nxt = cur->next;   // STORE NEXT
                cur->next = prev;            // reverse
                prev = cur;
                cur = nxt;
            }

            // reconnect
            ListNode* oldStart = start->next;
            start->next = prev;
            start = oldStart;
            temp = check;
        }
    }
};
