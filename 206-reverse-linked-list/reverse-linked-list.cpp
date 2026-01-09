/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* x=head;
        ListNode* p=nullptr;
        while(x!=nullptr){
            ListNode* t=x->next;
            x->next=p;
            p=x;
            x=t;
        }return p;
    }
};