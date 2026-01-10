class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> visited;
        ListNode* curr = head;

        while (curr != nullptr) {
            for (int i = 0; i < visited.size(); i++) {
                if (visited[i] == curr)
                    return true;
            }
            visited.push_back(curr);
            curr = curr->next;
        }
        return false;
    }
};
