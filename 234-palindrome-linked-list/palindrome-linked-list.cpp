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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* temp=head;
        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
            temp=slow;
        }
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* x=temp->next;
            temp->next=prev;
            prev=temp;
            temp=x;
        }
        while(prev!=nullptr){
            if(prev->val != head->val) return false;
            prev=prev->next;
            head=head->next;
        }
        return true;
    }
};