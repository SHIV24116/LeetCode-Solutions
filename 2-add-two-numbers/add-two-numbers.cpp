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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d=new ListNode(0);
        ListNode* ans=d;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr){
            int a=0;
            int b=0;
            if(l1!=nullptr){
                a=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                b=l2->val;
                l2=l2->next;
            }
            ListNode* z=new ListNode((a+b+carry)%10);
            carry=(a+b+carry)/10;
            ans->next=z;
            ans=ans->next;
        }
        if(carry!=0){
            ListNode* z=new ListNode(carry);
            ans->next=z;
        }
        return d->next;
    } 
};