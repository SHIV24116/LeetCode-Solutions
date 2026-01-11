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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        int l=0;
        ListNode* f=head;
        while(f!=nullptr && f->next!=nullptr){
            l++;
            f=f->next->next;
            if(f==nullptr) l=2*l;
            else if(f->next==nullptr) l=2*l+1;
        }
        int z=l-n+1;
        if(z==1) return head->next;
        l=1;
        ListNode* temp =head;
        while(temp!=nullptr){
            l++;
            if(l==z) temp->next=temp->next->next;
            temp=temp->next;
        }return head;
    }
};