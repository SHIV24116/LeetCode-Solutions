/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* temp=head;
        vector<ListNode*>v;
        while(temp->next!=nullptr){
            for(int i=0;i<v.size();i++){
                if(temp->next==v[i]) return v[i];
            }
            v.push_back(temp);
            temp=temp->next;
        }
        return nullptr;
    }
};