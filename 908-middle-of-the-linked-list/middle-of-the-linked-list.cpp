class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int ct = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            ct++;
            temp = temp->next;
        }

        int steps = ct / 2;   
        ListNode* ans = head;

        while (steps--) {
            ans = ans->next;
        }

        return ans;
    }
};
