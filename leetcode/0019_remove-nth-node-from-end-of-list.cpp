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
        int m=1;
        if(head==nullptr){
            return head;
        }
        ListNode *p=head;
        while(p->next!=nullptr){
            m++;
            p=p->next;
        }
        ListNode *q=head;
         m=m-n;
        if(m==0){
            head=head->next;
            return head;
        }
        if(n==0){
            ListNode *l=head;
            for(int i=0;l->next!=p;i++){
                l=l->next;
            }
            l->next=nullptr;
            return head;
        }
        for(int i=0;i<m-1;i++){
            q=q->next;
        }
        p=q->next;
        p=p->next;
        q->next=p;
        

        return head;
        
    }
};
